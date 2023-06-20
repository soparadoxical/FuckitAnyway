#include "shutdown.h"
#include "eventqueue.h"
#include "display.h"
#include "render_timer.h"
#include "world_cycle_timer.h"
#include "engine_options.h"

int system_shutdown()
{
  destroy_event_queue();
  destroy_world_cycle_timer();
  destroy_render_timer();
  destroy_main_display();
  shutdown_engine_options();
  al_uninstall_system();
  return 0;
}
