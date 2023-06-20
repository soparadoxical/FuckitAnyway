#include <allegro5/allegro.h>
#ifndef MEDIUM_ETHER_H
#define MEDIUM_ETHER_H


void initialize_local_ether(ALLEGRO_CONFIG* config);
void set_default_local_ether_value(double x, ALLEGRO_CONFIG* config);
void destroy_local_ether(double **x);
double get_local_ether_value(double x);
void set_default_grand_ether_value(double x,ALLEGRO_CONFIG* config);
double get_grand_ether_value(double y);
void sync_grand_ether(double x,double y);
void sync_local_ether(double x,double y);


#endif
