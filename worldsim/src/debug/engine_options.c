#include <allegro5/allegro.h>
#include <string.h>
#include "engine_options.h"
#include "error_handling.h"
#include "utility.h"


struct engine_options
{
  int display_width;
  int display_height;
  int render_refresh_rate;
  ALLEGRO_COLOR display_background;
  int world_border_size;
  int world_size;
  int world_position;
  int world_thickness;
  ALLEGRO_COLOR world_color;
};

engine_options* options = NULL;

void initialize_display_resolution(ALLEGRO_CONFIG* config);
void paint_display_background(ALLEGRO_CONFIG* config);
void initialize_render_rate(ALLEGRO_CONFIG* config);
void initialize_world_drawing_properties(ALLEGRO_CONFIG* config);
void initialize_world_properties(ALLEGRO_CONFIG* config);

void initialize_engine_options(ALLEGRO_CONFIG* config)
{
  options = malloc(sizeof(engine_options));
  if (options == NULL)
    handle_installation_error(MEMORY_ALLOCATION_FAILED_OPTIONS);

  initialize_display_resolution(config);
  paint_display_background(config);
  initialize_render_rate(config);
  initialize_world_drawing_properties(config);
  initialize_world_properties(config);
}

void shutdown_engine_options()
{
  free(options);
}

void initialize_display_resolution(ALLEGRO_CONFIG* config)
{
  const char* resolution;
  if (config != NULL)
    resolution = al_get_config_value(config, "display", "resolution");
  else
    resolution = NULL;
  
  int width, height;
  int chosen = 0;

  if (resolution == NULL)
    {
      width = 800;
      height = 600;
      chosen = 1;
    }

  if (!chosen && (strcmp(resolution, "800x600") == 0))
    {
      width = 800;
      height = 600;
      chosen = 1;
    }
  
  if (!chosen && (strcmp(resolution, "1024x768") == 0))
    {
      width = 1024;
      height = 768;
      chosen = 1;
    }

  if (!chosen && (strcmp(resolution, "1360x768") == 0))
    {
      width = 1360;
      height = 768;
      chosen = 1;
    }
  
  if (!chosen)
    {
      width = 800;
      height = 600;
    }

  options->display_width = width;
  options->display_height = height;
}

void paint_display_background(ALLEGRO_CONFIG* config)
{
  const char* color;
  if (config != NULL)
    color = al_get_config_value(config, "display", "background");
  else
    color = NULL;
  
  if (color == NULL)
    color = "#282a36";
  options->display_background = hex_to_color(color);
}

void initialize_render_rate(ALLEGRO_CONFIG* config)
{
  const char* render_rate;
  if (config != NULL)
    render_rate = al_get_config_value(config, "engine", "render rate");
  else
    render_rate = NULL;
  
  if (render_rate == NULL)
    render_rate = "60";

  int r_rate = atoi(render_rate);

  if (r_rate <= 0)
    r_rate = 60;
  
  options->render_refresh_rate = atoi(render_rate);
}

void initialize_world_drawing_properties(ALLEGRO_CONFIG* config)
{
    options->world_border_size = 500;
    options->world_position = 20;
    options->world_thickness = 2;

    const char* color = NULL;
    if (config != NULL)
      color = al_get_config_value(config, "world", "color");
    else
      color = NULL;
    
    if (color == NULL)
      color = "#44475a";
    options->world_color = hex_to_color(color);
}

void initialize_world_properties(ALLEGRO_CONFIG* config)
{
  const char* size;
  if (config != NULL)
    size = al_get_config_value(config, "world", "size");
  else
    size = NULL;
  
  int isize = 0;
  
  if (size == NULL)
    isize = 50;
  else
    isize = atoi(size);

  options->world_size = isize;
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

int get_world_border_size()
{
  return options->world_border_size;
}

int get_world_size()
{
  return options->world_size;
}

int get_world_position()
{
  return options->world_position;
}

int get_world_thickness()
{
  return options->world_thickness;
}

ALLEGRO_COLOR get_world_color()
{
  return options->world_color;
}

