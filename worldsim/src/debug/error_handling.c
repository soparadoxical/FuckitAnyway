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
    case RENDER_TIMER_FAILED:
      fprintf(stderr, "Failed to create the render timer.\n");
      break;
    case MEMORY_ALLOCATION_FAILED_OPTIONS:
      fprintf(stderr, "Malloc returned NULL when trying to allocate space for options in engine options.\n");
    case WORLD_CYCLE_TIMER_FAILED:
      fprintf(stderr, "Failed to create the world cycle timer.\n");
      break;
    default:
      fprintf(stderr, "Unknown error code supplied...\n");
    }
  exit(code);
}

void handle_mainLoop_error(int code)
{
}
