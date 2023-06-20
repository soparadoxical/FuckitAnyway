#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <allegro5/allegro.h>
#include "medium_ether.h"
#include "engine_options.h"
#include "error_handling.h"



void initialize_local_ether(ALLEGRO_CONFIG* config);
void set_default_local_ether_value(double x, ALLEGRO_CONFIG* config);
void destroy_local_ether(double **x);
double get_local_ether_value(double x);
void set_default_grand_ether_value(double x,ALLEGRO_CONFIG* config);
double get_grand_ether_value(double y);
void sync_grand_ether(double x,double y);
void sync_local_ether(double x,double y);

void initialize_local_ether(ALLEGRO_CONFIG* config)
{
    double grand_ether=0;
	double row = get_world_size();
	double coloumn = get_world_size();
	double **local_ether = (double **)malloc(row * sizeof(double*));        
    if (local_ether == NULL)
    {
       handle_installation_error(MEMORY_ALLOCATION_FAILED_OPTIONS); 
    }
    for (int i = 0; i < row; ++i)
    {
        local_ether[i] = (double *)malloc(coloumn * sizeof(double));
        if (local_ether[i] == NULL)
        {
            handle_installation_error(MEMORY_ALLOCATION_FAILED_OPTIONS);
        }
    }
}

void destroy_local_ether(double **x)
{
    for (int i = 0; i < sizeof(x); i++)
        free(x[i]);
}

void set_default_local_ether_value(double x, ALLEGRO_CONFIG* config)
{
	const char* default_local_ether;
    if (config != NULL)
        default_local_ether = al_get_config_value(config, "ether", "default_local_ether_value" );
    else
        default_local_ether = NULL;
    
    double ether_value;
    double chosen = 0;

    if(default_local_ether == NULL)
    {
        ether_value = 5;
        chosen = 1;
    }
    
    if(!chosen && (strcmp(default_local_ether, "5") == 0))
    {
        ether_value = 5;
        chosen = 1;
    }

    if(!chosen)
    {
        ether_value = 5;
    }

    x = ether_value;
}

double get_local_ether_value(double x)
{
	return x;
}

void set_default_grand_ether_value(double x, ALLEGRO_CONFIG* config)
{
	const char* default_grand_ether;
    if (config != NULL)
        default_grand_ether = al_get_config_value(config, "ether", "default_grand_ether_value" );
    else
        default_grand_ether = NULL;
    
    double ether_value;
    double chosen = 0;

    if(default_grand_ether == NULL)
    {
        ether_value = 100;
        chosen = 1;
    }
    
    if(!chosen && (strcmp(default_grand_ether, "100") == 0))
    {
        ether_value = 100;
        chosen = 1;
    }

    if(!chosen)
    {
        ether_value = 100;
    }

    x = ether_value;
}

double get_grand_ether_value(double x)
{
	return x;
}

//sync grand ether using local ether 
void sync_grand_ether(double x,double y)
{
    double temp=0;
	for(int i = 0; i<sizeof(x); ++i){
        temp = temp + x;
    }
    y=temp/sizeof(x);
}

//sync local ether using grand ether
void sync_local_ether(double x, double y)
{
    double temp;
    if(x < y)
    {
        temp=( y - x )/2;
        x = x + temp / 2;
    }
    else
    {
        temp=( y - x )/2;
        x = x - temp / 2;
    }
}

