#include "eventqueue.h"
#include "display.h"
#include "render_timer.h"
#include <allegro5/allegro.h>

ALLEGRO_EVENT_QUEUE* queue = NULL;

void create_event_queue()
{
  queue = al_create_event_queue();
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_mouse_event_source());
  al_register_event_source(queue, al_get_display_event_source(main_display));
  al_register_event_source(queue, al_get_timer_event_source(render_timer));
};
