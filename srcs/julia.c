/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:01:08 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/21 17:28:46 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

/**
 * Maps the a dimention into another by scaling it.
 *	z = z^2 + c
 *
 */
void  calc_julia(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int iterations;
	uint32_t color;

	iterations = 0;
	z.x = (scale_between(x, -2, +2, WIN_WIDTH - 1) * fractal->zoom) + fractal->shift_x;
	z.y = (scale_between(y, +2, -2, WIN_HEIGHT - 1) * fractal->zoom) + fractal->shift_y;
    c.x = fractal->c.x;
	c.y = fractal->c.y;
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