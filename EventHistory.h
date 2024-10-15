#ifndef EVENT_HISTORY_H
#define EVENT_HISTORY_H

#include "PongEvent.h"

struct Node {
    struct PongEvent event;
    struct Node* next;
};

struct EventHistory {
    struct Node* event_list_head;

    void (*add_event)(struct EventHistory* self, struct PongEvent new_event);
    void (*save_event_history)(struct EventHistory* self, const char* filename);
};

// Funciones públicas
void EventHistory_init(struct EventHistory* self);
void EventHistory_add_event(struct EventHistory* self, struct PongEvent new_event);
void EventHistory_save_event_history(struct EventHistory* self, const char* filename);

#endif // EVENT_HISTORY_H
