#include "world_cycle_timer.h"
#include "error_handling.h"

ALLEGRO_TIMER* world_cycle_timer = NULL;

void create_world_cycle_timer()
{
  world_cycle_timer = al_create_timer(1.0);
  if (world_cycle_timer == NULL)
    handle_installation_error(WORLD_CYCLE_TIMER_FAILED);
}

void destroy_world_cycle_timer()
{
  al_destroy_timer(world_cycle_timer);
}

ALLEGRO_TIMER* get_world_cycle_timer()
{
  return world_cycle_timer;
}

double get_world_cycle_rate()
{
  return al_get_timer_speed(world_cycle_timer);
}

void set_world_cycle_rate(double value)
{
  al_set_timer_speed(world_cycle_timer, value);
}
