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
int	ft_terminate(t_fractal *frac)
{
	if (frac && frac->mlx_win)
		mlx_destroy_window(frac->mlx, frac->mlx_win);
	exit (1);
}

/**
 * Select Fractal Type
 *
 *
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
*/

/**
 * Put colored pixel in image 
 *
 */

void mlx_put_pixel(mlx_img_t	*img, int x, int y , uint32_t color) 
{
	int pixelpos;

	pixelpos = (y * img->line_len) + (x * img->bpp / 8);
	*(unsigned int * )(img->pixels + pixelpos) = color;
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
			if (!ft_strncmp("mandelbrot", fractal->title, 10))
				calc_mandelbrot(x, y, fractal);
			else if (!ft_strncmp("julia", fractal->title, 5))
				calc_julia(x, y, fractal);
			else if (!ft_strncmp("burningship", fractal->title, 11))
				calc_burningships(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img.img, 0, 0);
}
