#include "eventqueue.h"
#include "display.h"
#include "render_timer.h"
#include "world_cycle_timer.h"
#include <allegro5/allegro.h>

ALLEGRO_EVENT_QUEUE* queue = NULL;

void create_event_queue()
{
  queue = al_create_event_queue();
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_mouse_event_source());
  al_register_event_source(queue, al_get_display_event_source(get_main_display()));
  al_register_event_source(queue, al_get_timer_event_source(get_render_timer()));
  al_register_event_source(queue, al_get_timer_event_source(get_world_cycle_timer()));
};

void destroy_event_queue()
{
  al_destroy_event_queue(queue);
}

ALLEGRO_EVENT_QUEUE* get_event_queue()
{
  return queue;
}
