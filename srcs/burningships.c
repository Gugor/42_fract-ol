/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningships.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:01:08 by hmontoya          #+#    #+#             */
/*   Updated: 2024/01/25 19:02:34 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Maps the a dimention into another by scaling it.
 *	z = z^2 + c
 *
 */
void	calc_burningships(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			iterations;
	uint32_t	color;

	iterations = -1;
	c.x = 0.0;
	c.y = 0.0;
	c.x = scale_between(x, -2, +2, WIN_WIDTH - 1) * f->zoom + f->shift_x;
	c.y = scale_between(y, +2, -2, WIN_HEIGHT - 1) * f->zoom + f->shift_y;
	while (++iterations < f->definition)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->limit)
		{
			color = (uint32_t)scale_between(iterations, f->colors[0],
					f->colors[1], f->definition);
			mlx_put_pixel(&f->img, x, y, color);
			return ;
		}
		mlx_put_pixel(&f->img, x, y, g_hexcolors[f->colors[2]]);
	}
}
