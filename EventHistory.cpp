#include "EventHistory.h"
#include <stdio.h>
#include <stdlib.h>

void EventHistory_init(struct EventHistory* self) {
    self->event_list_head = NULL;
    self->add_event = EventHistory_add_event;
    self->save_event_history = EventHistory_save_event_history;
}

void EventHistory_add_event(struct EventHistory* self, struct PongEvent new_event) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for node.\n");
        return;
    }
    new_node->event = new_event;
    new_node->next = self->event_list_head;
    self->event_list_head = new_node;
}

void EventHistory_save_event_history(struct EventHistory* self, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing event history.\n");
        return;
    }

    struct Node* current = self->event_list_head;
    while (current != NULL) {
        struct PongEvent event = current->event;
        fprintf(file, "%d|%d|%d|%d|%d|%d\n", event.timestamp, event.ball_x, event.ball_y, event.paddle_x, event.paddle_y, event.score);
        current = current->next;
    }
    fclose(file);
}
