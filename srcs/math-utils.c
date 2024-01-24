/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:00:20 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/21 16:37:14 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Maps the a dimention into another by scaling it.
 *  
*/
  double scale_between(double unscaled, double min_limit, double max_limit, double max)
  {
	  int min;

	  min = 0;
      return((max_limit - min_limit) * (unscaled - min) / (max - min) +                min_limit);
  }

/**
 * Calculate de image desplacment to the mouse position 
 * (mousepos - centerofscreen) / windowswidth) * zoom 
 */
void zoom_to_mouse(int x, int y, t_fractal *fractal)
{
	if (x > 0)
		fractal->shift_x += ((double)x - (WIN_WIDTH / 2)) / WIN_WIDTH * fractal->zoom;
	else
		fractal->shift_x -= ((double)x - (WIN_WIDTH / 2)) / WIN_WIDTH * fractal->zoom;
	if (y > 0)
		fractal->shift_y -= ((double)y - (WIN_HEIGHT / 2)) / WIN_HEIGHT * fractal->zoom;
	else
		fractal->shift_y += ((double)y - (WIN_HEIGHT / 2)) / WIN_HEIGHT * fractal->zoom;
}

/**
 * Print a complex number type
 * @dev puropuses
 */
