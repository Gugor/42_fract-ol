/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:01:08 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/21 17:28:46 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

/**
 * Free memory and clear window
 */
int	ft_memfree(t_fractal *frac)
{
	if (frac && frac->mlx_win)
		mlx_destroy_window(frac->mlx, frac->mlx_win);
	exit (1);
}

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
 * Put colored pixel in image 
 *
 */

static void mlx_put_pixel(mlx_img_t	*img, int x, int y , uint32_t color) 
{
	int pixelpos;

	pixelpos = (y * img->line_len) + (x * img->bpp * 8);
	*(unsigned int * )(img->pixels + pixelpos) = color;
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

	z.x = (scale_between(x, -2, +2, WIN_WIDTH - 1) * fractal->zoom) + fractal->shift_x;
	z.y = (scale_between(y, +2, -2, WIN_HEIGHT - 1) * fractal->zoom) + fractal->shift_y;
	
	select_fractal_set(&z, &c, fractal);

	while (iterations < fractal->definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->limit)
		{
			color = (uint32_t)scale_between(iterations, fractal->colors[0], fractal->colors[1], fractal->definition);
			mlx_put_pixel(&fractal->img, x, y, color);	
			return ;
		}
		mlx_put_pixel(&fractal->img, x, y, g_hexcolors[fractal->colors[2]]);
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
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img.img, 0, 0);
}
