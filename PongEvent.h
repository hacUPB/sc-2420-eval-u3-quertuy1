#pragma once
#ifndef PONG_EVENT_H
#define PONG_EVENT_H

struct PongEvent {
    int timestamp;
    int ball_x, ball_y;
    int paddle_x, paddle_y;
    int score;
};

#endif // PONG_EVENT_H

