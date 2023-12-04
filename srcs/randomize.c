#include "fractol.h"

/**
 * Set the seed to randomize
 */
void set_seed()
{
	srand(time(NULL));
}

/**
 * Get a random number
 */
int randomize(int min, int max) 
{
    return (min + rand() % (max - min + 1));
}
