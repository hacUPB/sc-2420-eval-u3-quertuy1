#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

struct GameObject {
    float x, y;
    float width, height;
    float vel_x, vel_y;

    void (*update)(struct GameObject* self, float delta_time);
};

// Funciones públicas
void GameObject_init(struct GameObject* self, float x, float y, float width, float height, float vel_x, float vel_y);
void GameObject_update(struct GameObject* self, float delta_time);

#endif // GAME_OBJECT_H
