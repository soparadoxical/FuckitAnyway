#include <allegro5/allegro.h>
#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

void create_event_queue();
void destroy_event_queue();
ALLEGRO_EVENT_QUEUE* get_event_queue();
#endif
