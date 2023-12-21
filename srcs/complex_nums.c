#include "fractol.h"

/**
 * Adds two complex numbers
 *
 */
t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/**
 * Squares two complex numbers 
 *
 */
t_complex square_complex(t_complex z)
{
	t_complex result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
/**
 * Divide a complex number
 *  z / c = (z.x * c.x + z.y * c.y) + (z.y * c.x - z.x * c.y)i
 *         / ________________________________________________
 *								c.x^2 + c.y^2
 */

 t_complex divide_complex(t_complex a, t_complex b)
 {
	t_complex z;
	double divisor_x;
	double divisor_y;

	divisor_x = 0;
	divisor_y = 0;
	
	divisor_x = (a.x * b.x) + (a.y * b.y);
	divisor_y = (a.y * b.x) - (a.x * b.y);
	
	z.x = divisor_x / (a.x * a.x);
	z.y = divisor_y / (a.y * a.y);
	return (z);

 }

/**
 * Rest complex numbers
 * 
 */
t_complex rest_complex(t_complex a, t_complex b)
{
	t_complex z;

	z.x = (a.x - b.x);
	z.y = (a.y - b.y);
	return (z);
}

/**
 * Multiply complex number
 *
 */
t_complex multiply_complex(t_complex c1, t_complex c2)
{
	t_complex result;

	result.x = (c1.x * c2.x - c1.y * c2.y); 
	result.y = (c1.x * c2.y + c1.y * c2.x);
	return (result);
}

/**
 * Print a complex number type
 * @dev puropuses
 */
void print_complex(t_complex z)
{
	t_complex a;
	int i;

	a = z;
	i = 100;
	while ( i > 0)
	{
		printf("real = %.f , imaginary = %.f\n ", a.x, a.y);
		a = sum_complex(square_complex(a), a);
		i--;
	}
}
