#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "GameObject.h"
#include "EventHistory.h"

struct Game {
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Texture* text_texture;
    int last_frame_time;
    int score;

    struct GameObject ball;
    struct GameObject paddle;
    struct EventHistory event_history;

    bool is_running;

    void (*initialize)(struct Game* self);
    void (*process_input)(struct Game* self);
    void (*update)(struct Game* self);
    void (*render)(struct Game* self);
    void (*setup)(struct Game* self);
    void (*destroy)(struct Game* self);
};

// Funciones públicas
void Game_init(struct Game* self);
void Game_initialize(struct Game* self);
void Game_process_input(struct Game* self);
void Game_update(struct Game* self);
void Game_render(struct Game* self);
void Game_setup(struct Game* self);
void Game_destroy(struct Game* self);

#endif // GAME_H
