# include "fractol.h"

/**
 * Select Fractal Type
 *
 */
static void select_fractal_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp("julia", fractal->title, 5))
	{
		c->x = fractal->c.x;
		c->y = fractal->c.y;
	}
	else 
	{
		c->x = z->x;
		c->y = z->y;
	}
}


/**
 * Maps the a dimention into another by scaling it.
 *	z = z^2 + c
 *
 */
static void  calculate_man_jul_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int iterations;
	uint32_t color;

	iterations = 0;

	z.x = (scale_between(x, -2, +2, 0, WIN_WIDTH - 1) * fractal->zoom) + fractal->shift_x;
	z.y = (scale_between(y, +2, -2, 0, WIN_HEIGHT - 1) * fractal->zoom) + fractal->shift_y;
	
	select_fractal_set(&z, &c, fractal);

	mlx_put_pixel(fractal->img, x, y, hexcolors[fractal->colors[2]]);
	while (iterations < fractal->definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->limit)
		{
			color = (uint32_t)scale_between(iterations, fractal->colors[0], fractal->colors[1], 0, fractal->definition);
			mlx_put_pixel(fractal->img, x, y, color);	
			return ;
		}
		iterations++;
	}
}
/**
 *  Calculate Newton fractal
 *   z = z - ((z^3-1) / (3z^2)
 */
static void calculate_newton_pixel(int32_t x, int32_t y, t_fractal *fractal)
{
	t_complex z;
	int iterations;
	uint32_t color;
	t_complex p;
	t_complex p1;

	iterations = 0;

	printf("Initializing z...\n");
	z.x = (scale_between(x, -2, +2, 0, WIN_WIDTH - 1) * fractal->zoom) + fractal->shift_x;
	z.y = (scale_between(y, +2, -2, 0, WIN_HEIGHT - 1) * fractal->zoom) + fractal->shift_y;

	printf("Enreting Loop...\n");
	while (iterations < fractal->definition)
	{
		//Resolve p(z^3- 3z + 1)
		p.x = (z.x * z.x * z.x) - (3 * (z.x * z.x * z.x * z.y * z.y * z.y)) - 1; // - ((z.y * z.y * z.y) - 1);
		p.y = (3 * z.x * z.x * z.y * z.x) - (z.y * z.y * z.y); // - 1;
		//Resolve p1(3z2)
		p1.x = (3 * (z.x * z.x) * z.y) - (3 * (p1.y * p1.y)); //(z.x * 3 - z.y * 3);
		p1.y = 6 * z.x * z.y; //(z.x * 3 + z.y * 3);
		//Resolve z - (p/p1)
		z = rest_complex(z, divide_complex(p,p1)); 
		
		if ((z.x * z.x) + (z.y * z.y) > 2)
		{
			color = (uint32_t)scale_between(iterations, fractal->colors[0], fractal->colors[1], 0, fractal->definition);
			mlx_put_pixel(fractal->img, x, y, color);	
			return ;
		}
		iterations++;
	}


	return ;
}
/**
 * Renders the current fractal on window screen
 *
 */
void fractal_render(t_fractal *fractal)
{
	uint32_t x;
	uint32_t y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			if (!ft_strncmp(fractal->title, "julia", 5) || !ft_strncmp(fractal->title,"mandelbrot", 10))
				calculate_man_jul_pixel(x, y, fractal);
			else if (ft_strncmp(fractal->title,"newton", 6))
				calculate_newton_pixel(x, y, fractal);
		}
	}
}
