#include<stdio.h>
#include<stdlib.h>
#include "ether.h"
#include "engine_options.h"

extern double *grand_ether = NULL;
extern double **local_ether = NULL;
extern int count = 0;
void initialize_grid();
void set_default_local_ether_value(int,int);
double get_local_ether_value(int,int);
void set_default_grand_ether_value();
double get_grand_ether_value();
int get_counter();
void sync_local_ether(int,int);
void sync_grand_ether();
void destroy_ether();


void initialize_grid()
{
	count = 5;//get_world_size();
	grand_ether = (double *)malloc(sizeof(double));
	local_ether = (double **)malloc(count * sizeof(double*));        
    if (local_ether == NULL)
    {
       exit(0); 
    }
    for (int i = 0; i < count; ++i)
    {
        local_ether[i] = (double *)malloc(count * sizeof(double));
        if (local_ether[i] == NULL)
        {
            exit(0);
        }
    }

    for(int r = 0; r <count; ++r )
    {
    	for (int c = 0; c < count; ++c)
    	{
    		set_default_local_ether_value(r,c);
    	}
    }

    set_default_grand_ether_value();
}

void set_default_local_ether_value(int r,int c)
{
	local_ether[r][c]=5;
}

double get_local_ether_value(int r,int c)
{
	return local_ether[r][c];
}

void set_default_grand_ether_value()
{
	*grand_ether = 100;
}

double get_grand_ether_value(){
	return *grand_ether;
}

int get_counter()
{
	return count;
}

void sync_local_ether(int r,int c)
{
	double GE = get_grand_ether_value();
	double temp;
    if(local_ether[r][c] < GE)
    {
        temp = ( GE - local_ether[r][c] )/2;
        local_ether[r][c] = local_ether[r][c] + temp / 2;
    }
    else
    {
        temp = (local_ether[r][c] - GE)/2;
        local_ether[r][c] = local_ether[r][c] - temp / 2;
    }
}

void sync_grand_ether()
{
	double temp = 0;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			temp = temp + local_ether[i][j];
		}
	}
	*grand_ether = temp/count;
}

void destroy_ether()
{
	printf("Destroying...");
	for (int i = 0; i < count; i++)
        free(local_ether[i]);
    free(local_ether);
    free(grand_ether);
}

int main(int argc, char const *argv[])
{
	double temp;
	initialize_grid();
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			temp = get_local_ether_value(i,j);
			printf("%lf\n",temp );
		}
	}
	temp = get_grand_ether_value();
	printf("%lf\n",temp );

	sync_grand_ether();
	temp = get_grand_ether_value();
	printf("%lf\n",temp );

	sync_local_ether(1,2);
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			temp = get_local_ether_value(i,j);
			printf("%lf\n",temp );
		}
	}

	sync_grand_ether();
	temp = get_grand_ether_value();
	printf("%lf\n",temp );

	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			sync_local_ether(i,j);
		}
	}

	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			temp = get_local_ether_value(i,j);
			printf("%lf\n",temp );
		}
	}
	destroy_ether();

	/*temp = get_grand_ether_value();
	printf("%lf\n",temp );
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			temp = get_local_ether_value(i,j);
			printf("%lf\n",temp );
		}
	}*/

	return 0;
}
