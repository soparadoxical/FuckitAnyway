#include<stdio.h>
#include<stdlib.h>
#include "medium_ether.h"
#include "engine_options.h"


int grand_ether;
void initialize_local_ether()
{
	int row = get_world_size();
	int coloumn = get_world_size();
	int **local_ether = (int **)malloc(row * sizeof(int *));        
    if (local_ether == NULL)
    {
       handle_installation_error(MEMORY_ALLOCATION_FAILED_OPTIONS); 
    }
    for (int i = 0; i < row; ++i)
    {
        local_ether[i] = (int *)malloc(coloumn * sizeof(int));
        if (local_ether[i] == NULL)
        {
            handle_installation_error(MEMORY_ALLOCATION_FAILED_OPTIONS);
        }
    }
}

void set_default_local_ether_value(ALLEGRO_CONFIG* config)
{
	const char* local_ether;
    if( config != NULL)
        
}

int get_local_ether_value(int x)
{
	return x;
}

void set_grand_ether_value()
{
	grand_ether=100;
}

int get_grand_ether_value()
{
	return grand_ether;
}

//sync grand ether using local ether 
void sync_grand_ether(int x)
{
	float temp=grand_ether;
	if(temp<x)
		temp=x;
	grand_ether = temp + (temp-grand_ether);
}

//sync local ether using grand ether
void sync_local_ether()
{

}

