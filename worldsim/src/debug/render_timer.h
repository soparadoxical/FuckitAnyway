#include <allegro5/allegro.h>
#ifndef RENDER_TIMER_H
#define RENDER_TIMER_H

void create_render_timer();
void destroy_render_timer();
ALLEGRO_TIMER* get_render_timer();
#endif
