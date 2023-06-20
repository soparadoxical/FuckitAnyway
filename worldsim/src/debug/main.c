#include "initialize.h"
#include "main_loop.h"
#include "shutdown.h"
#include "error_handling.h"

int main(int argc, char** argv)
{
  int install_status_code = system_install();
  if (install_status_code != 0)
    handle_installation_error(install_status_code);

  int mainLoop_status_code = 0;
  while (mainLoop_status_code == 0)
    mainLoop_status_code = mainLoop();
  
  if (mainLoop_status_code != 1)
    handle_mainLoop_error(mainLoop_status_code);

  int shutdown_status_code = system_shutdown();
  
  return shutdown_status_code;
}
