#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>

void handle_installation_error(int code)
{
  switch(code)
    {
    case ALLEGRO_INSTALLATION_FAILED:
      fprintf(stderr, "Failed to initialize the Allegro library!\n");
      break;
    case ENGINE_CONFIG_NOT_FOUND:
      fprintf(stderr, "Failed to load engine.config config file!\n");
      break;
    case ENGINE_CONFIG_NO_DISPLAY_WIDTH:
      fprintf(stderr, "Invalid width value in [display] in engine.config\n");
      break;
    case ENGINE_CONFIG_NO_DISPLAY_HEIGHT:
      fprintf(stderr, "Invalid height value in [display] in engine.config\n");
      break;
    case MAIN_DISPLAY_CREATION_FAILED:
      fprintf(stderr, "Failed to create the main display!\n");
      break;
    case KEYBOARD_INSTALLATION_FAILED:
      fprintf(stderr, "Failed to install a keyboard driver!\n");
      break;
    case MOUSE_INSTALLATION_FAILED:
      fprintf(stderr, "Failed to install a mouse driver!\n");
      break;
    case ALLEGRO_PRIMITIVES_ADDON_INSTALLATION_FAILED:
      fprintf(stderr, "Failed to initialize the allegro primitives addon!\n");
      break;
    case ENGINE_CONFIG_NO_RENDER_RATE:
      fprintf(stderr, "Invalid render rate value in [engine] in engine.config\n");
      break;
    case RENDER_TIMER_FAILED:
      fprintf(stderr, "Failed to create the render timer.\n");
      break;
    default:
      fprintf(stderr, "Unknown error code supplied...\n");
    }
  exit(code);
}

void handle_mainLoop_error(int code)
{
}
