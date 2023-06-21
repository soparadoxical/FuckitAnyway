#include<stdio.h>
#include<stdlib.h>
#ifndef ETHER_H
#define ETHER_H

extern double *grand_ether;
extern double **local_ether;
extern int count;

void initialize_grid();
void set_default_local_ether_value(int ,int );
double get_local_ether_value(int,int);
void set_default_grand_ether_value();
double get_grand_ether_value();
int get_counter();
void sync_local_ether(int,int);
void sync_grand_ether();
void destroy_ether();	

#endif