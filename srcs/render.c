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
static void  calculate_pixel(int x, int y, t_fractal *fractal)
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
			calculate_pixel(x, y, fractal);
		}
	}
}
