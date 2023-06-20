#include <allegro5/allegro.h>
#ifndef WORLD_CYCLE_TIMER_H
#define WORLD_CYCLE_TIMER_H

void create_world_cycle_timer();
void destroy_world_cycle_timer();
ALLEGRO_TIMER* get_world_cycle_timer();

double get_world_cycle_rate();
void set_world_cycle_rate(double value);
#endif
