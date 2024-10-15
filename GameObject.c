#include "GameObject.h"

void GameObject_init(struct GameObject* self, float x, float y, float width, float height, float vel_x, float vel_y) {
    self->x = x;
    self->y = y;
    self->width = width;
    self->height = height;
    self->vel_x = vel_x;
    self->vel_y = vel_y;
    self->update = GameObject_update;
}

void GameObject_update(struct GameObject* self, float delta_time) {
    self->x += self->vel_x * delta_time;
    self->y += self->vel_y * delta_time;
}
