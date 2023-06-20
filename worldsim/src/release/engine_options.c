#include <allegro5/allegro.h>
#include "engine_options.h"
#include "error_handling.h"
#include "utility.h"


struct engine_options
{
  int display_width;
  int display_height;
  int render_refresh_rate;
  ALLEGRO_COLOR display_background;
  int world_width;
  int world_height;
  int world_size;
  int world_positionx;
  int world_positiony;
  int world_thickness;
  ALLEGRO_COLOR world_color;
};

engine_options* options = NULL;

engine_options* engine_options_initialize()
{
  engine_options* loptions = malloc(sizeof(engine_options));
  return loptions;
}

void engine_options_shutdown(engine_options* loptions)
{
  free(loptions);
}

void initialize_engine_options(ALLEGRO_CONFIG* config)
{
  options = engine_options_initialize();
  const char* display_width = al_get_config_value(config, "display", "width");
  if (display_width == NULL)
    handle_installation_error(ENGINE_CONFIG_NO_DISPLAY_WIDTH);
  const char* display_height = al_get_config_value(config, "display", "height");
  if (display_height == NULL)
    handle_installation_error(ENGINE_CONFIG_NO_DISPLAY_HEIGHT);
  
  options->display_width = atoi(display_width);
  options->display_height = atoi(display_height);

  const char* render_rate = al_get_config_value(config, "engine", "render rate");
  if (render_rate == NULL)
    handle_installation_error(ENGINE_CONFIG_NO_RENDER_RATE);

  options->render_refresh_rate = atoi(render_rate);

  options->display_background = hex_to_color(al_get_config_value(config, "display", "background"));

  options->world_width = atoi(al_get_config_value(config, "world", "width"));
  options->world_height = atoi(al_get_config_value(config, "world", "height"));
  options->world_size = atoi(al_get_config_value(config, "world", "size"));
  options->world_positionx = atoi(al_get_config_value(config, "world", "positionx"));
  options->world_positiony = atoi(al_get_config_value(config, "world", "positiony"));
  options->world_thickness = atoi(al_get_config_value(config, "world", "thickness"));
  options->world_color = hex_to_color(al_get_config_value(config, "world", "color"));
}

int get_display_width()
{
  return options->display_width;
}

int get_display_height()
{
  return options->display_height;
}

int get_render_refresh_rate()
{
  return options->render_refresh_rate;
}

ALLEGRO_COLOR get_display_background()
{
  return options->display_background;
}

int get_world_width()
{
  return options->world_width;
}

int get_world_height()
{
  return options->world_height;
}

int get_world_size()
{
  return options->world_size;
}

int get_world_positionx()
{
  return options->world_positionx;
}

int get_world_positiony()
{
  return options->world_positiony;
}

int get_world_thickness()
{
  return options->world_thickness;
}

ALLEGRO_COLOR get_world_color()
{
  return options->world_color;
}

