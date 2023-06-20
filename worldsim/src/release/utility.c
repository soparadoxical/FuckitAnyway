#include <allegro5/allegro.h>
#include "utility.h"

ALLEGRO_COLOR hex_to_color(const char* value)
{
  char red[2], green[2], blue[2];
  int ired, igreen, iblue;

  red[0] = value[1];
  red[1] = value[2];
  green[0] = value[3];
  green[1] = value[4];
  blue[0] = value[5];
  blue[1] = value[6];

  ired = hex_to_int(red[0]) * 16 + hex_to_int(red[1]);
  igreen = hex_to_int(green[0]) * 16 + hex_to_int(green[1]);
  iblue = hex_to_int(blue[0]) * 16 + hex_to_int(blue[1]);

  return al_map_rgb(ired, igreen, iblue);
}

int hex_to_int(char ch)
{
  switch(ch)
    {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    case 'a':
    case 'A':
      return 10;
    case 'b':
    case 'B':
      return 11;
    case 'c':
    case 'C':
      return 12;
    case 'd':
    case 'D':
      return 13;
    case 'e':
    case 'E':
      return 14;
    case 'f':
    case 'F':
      return 15;
    }
  return -1;
}
