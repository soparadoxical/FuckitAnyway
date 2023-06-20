#include "render_timer.h"
#include "engine_options.h"
#include "error_handling.h"
			   
ALLEGRO_TIMER* render_timer = NULL;
void create_render_timer()
{
  render_timer = al_create_timer(1.0 / get_render_refresh_rate());
  if (render_timer == NULL)
    handle_installation_error(RENDER_TIMER_FAILED);
}

void destroy_render_timer()
{
  al_destroy_timer(render_timer);
}

ALLEGRO_TIMER* get_render_timer()
{
  return render_timer;
}
