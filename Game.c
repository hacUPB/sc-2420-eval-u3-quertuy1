#include "Game.h"
#include <stdio.h>

void Game_init(struct Game* self) {
    self->is_running = false;
    self->score = 0;
    self->initialize = Game_initialize;
    self->process_input = Game_process_input;
    self->update = Game_update;
    self->render = Game_render;
    self->setup = Game_setup;
    self->destroy = Game_destroy;
}

void Game_initialize(struct Game* self) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        self->is_running = false;
        return;
    }
    self->window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_BORDERLESS);
    self->renderer = SDL_CreateRenderer(self->window, -1, 0);

    if (TTF_Init() != 0) {
        fprintf(stderr, "Error initializing SDL_ttf.\n");
        self->is_running = false;
        return;
    }

    GameObject_init(&self->ball, 20, 20, 15, 15, 300, 300);
    GameObject_init(&self->paddle, 375, 560, 150, 25, 0, 0);
    EventHistory_init(&self->event_history);

    self->font = TTF_OpenFont("Eloque-BlackItalic.ttf", 27);
    if (self->font == NULL) {
        fprintf(stderr, "Error loading font: %s\n", TTF_GetError());
        self->is_running = false;
    }

    self->is_running = true;
}

void Game_process_input(struct Game* self) {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        self->is_running = false;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
            self->is_running = false;
        if (event.key.keysym.sym == SDLK_LEFT)
            self->paddle.vel_x = -400;
        if (event.key.keysym.sym == SDLK_RIGHT)
            self->paddle.vel_x = 400;
        break;
    case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT)
            self->paddle.vel_x = 0;
        break;
    }
}

void Game_update(struct Game* self) {
    int time_to_wait = 16 - (SDL_GetTicks() - self->last_frame_time);
    if (time_to_wait > 0 && time_to_wait <= 16)
        SDL_Delay(time_to_wait);

    float delta_time = (SDL_GetTicks() - self->last_frame_time) / 1000.0;
    self->last_frame_time = SDL_GetTicks();

    self->ball.update(&self->ball, delta_time);
    self->paddle.update(&self->paddle, delta_time);

    if (self->ball.x <= 0 || self->ball.x + self->ball.width >= 800)
        self->ball.vel_x = -self->ball.vel_x;

    if (self->ball.y <= 0)
        self->ball.vel_y = -self->ball.vel_y;

    if (self->ball.y + self->ball.height >= self->paddle.y &&
        self->ball.x + self->ball.width >= self->paddle.x &&
        self->ball.x <= self->paddle.x + self->paddle.width) {
        self->ball.vel_y = -self->ball.vel_y;
        self->score += 15;
    }

    if (self->ball.y + self->ball.height > 600) {
        self->ball.x = 400;
        self->ball.y = 300;
        self->score = 0;
    }

    struct PongEvent event = { SDL_GetTicks(), self->ball.x, self->ball.y, self->paddle.x, self->paddle.y, self->score };
    self->event_history.add_event(&self->event_history, event);
}

void Game_render(struct Game* self) {

