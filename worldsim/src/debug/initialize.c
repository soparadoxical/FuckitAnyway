#include "initialize.h"
#include "engine_options.h"
#include "error_handling.h"
#include "display.h"
#include "eventqueue.h"
#include "render_timer.h"
#include "world_cycle_timer.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int system_install()
{
  if (!al_init())
    return ALLEGRO_INSTALLATION_FAILED;

  ALLEGRO_CONFIG* config = al_load_config_file("engine.config");
  
  initialize_engine_options(config);
  al_destroy_config(config);

  if (!create_main_display())
    return MAIN_DISPLAY_CREATION_FAILED;

  if (!al_install_keyboard())
    return KEYBOARD_INSTALLATION_FAILED;

  if (!al_install_mouse())
    return MOUSE_INSTALLATION_FAILED;

  if (!al_init_primitives_addon())
    return ALLEGRO_PRIMITIVES_ADDON_INSTALLATION_FAILED;

  create_render_timer();
  al_start_timer(get_render_timer());

  create_world_cycle_timer();
  al_start_timer(get_world_cycle_timer());

  create_event_queue();
  
  return 0;
}
