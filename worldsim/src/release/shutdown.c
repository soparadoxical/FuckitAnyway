#include "shutdown.h"
#include "eventqueue.h"
#include "display.h"
#include "render_timer.h"

int system_shutdown()
{
  al_destroy_timer(render_timer);
  al_destroy_event_queue(queue);
  al_destroy_display(main_display);
  return 0;
}
