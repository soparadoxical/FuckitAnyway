#include "main_loop.h"
#include "eventqueue.h"
#include "render_timer.h"
#include "engine_options.h"
#include "world_cycle_timer.h"
#include "world.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

void redraw_display();
int handle_keyboard_input();
void handle_timer_input(ALLEGRO_EVENT event);
void draw_world_border();
void draw_world_lines();
void draw_horizontal_lines(int i);
void draw_vertical_lines(int i);

int mainLoop()
{
  int status = 0;
  ALLEGRO_EVENT event;
  if (!al_is_event_queue_empty(get_event_queue()))
    {
      al_wait_for_event(get_event_queue(), &event);

      if (event.type == ALLEGRO_EVENT_TIMER)
	handle_timer_input(event);
      
      if (event.type == ALLEGRO_EVENT_KEY_DOWN)
	status = handle_keyboard_input();

      if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	status = 1;
    }
  return status;
}

void redraw_display()
{
  al_clear_to_color(get_display_background());
  draw_world_border();
  draw_world_lines();
  al_flip_display();
}

int handle_keyboard_input()
{
  ALLEGRO_KEYBOARD_STATE kbd_state;
  al_get_keyboard_state(&kbd_state);
  
  if (al_key_down(&kbd_state, ALLEGRO_KEY_ESCAPE))
    return 1;

  if (al_key_down(&kbd_state, ALLEGRO_KEY_SPACE))
    {
      calculate_next_world();
      return 0;
    }

  return 0;
}

void handle_timer_input(ALLEGRO_EVENT event)
{
  if (event.timer.source == get_world_cycle_timer())
    calculate_next_world();

  if (event.timer.source == get_render_timer()) 
    redraw_display();
}

void draw_world_border()
{
  al_draw_rectangle(get_world_position(), get_world_position(),
		    get_world_border_size() + get_world_position(), get_world_border_size() + get_world_position(),
		    get_world_color(), get_world_thickness());
}

void draw_world_lines()
{
  for (int i = 1; i < get_world_size(); ++i)
    {
      draw_horizontal_lines(i);
      draw_vertical_lines(i);
    }
}

void draw_horizontal_lines(int i)
{
  al_draw_line(get_world_position() + ((float)get_world_border_size() / get_world_size()) * i,
	       get_world_position(),
	       get_world_position() + ((float)get_world_border_size() / get_world_size()) * i,
	       get_world_position() + get_world_border_size(),
	       get_world_color(), 1);
}

void draw_vertical_lines(int i)
{
  al_draw_line(get_world_position(),
		get_world_position() + ((float)get_world_border_size() / get_world_size()) * i,
		get_world_position() + get_world_border_size(),
		get_world_position() + ((float)get_world_border_size() / get_world_size()) * i,
		get_world_color(), 1);
}
