#include <allegro5/allegro.h>
#include "display.h"
#include "engine_options.h"

ALLEGRO_DISPLAY* main_display = NULL;

int create_main_display()
{
  main_display = al_create_display(get_display_width(), get_display_height());
  if (main_display == NULL)
    return 0;
  else
    return 1;
}
