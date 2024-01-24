/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:09 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/21 17:16:56 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/events.h"
#include <X11/X.h>
/**
 * Close Fractol
 *
 */
int	close_fractol(int keysim, void *param)
{
	t_fractal *fractal;

	fractal = (t_fractal *)param;
	if (keysim == KEY_ESCAPE)
		ft_terminate(fractal);
	return (0);
}

/**
 * Zoom in out fractal with mouse wheel
 *
 */
int	scrollmouse(int button, int x, int y, void *param)
{
	t_fractal	*fractal;
	double		mod;
	double		oldzoom;

	fractal = (t_fractal *)param;
	mod = 0.05;
	oldzoom = fractal->zoom;
	if (button == 4)
	{
		fractal->zoom *= 1.0 - mod;
		zoom_to_mouse(x, y, fractal);
		fractal->offspeed *= 1.0 - mod;
		fractal_render(fractal);
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.0 + mod;
		zoom_to_mouse(x, y, fractal);
		fractal->offspeed *= 1.0 + mod;
		fractal_render(fractal);
	}
	return (0);
}

/**
 * Move the fractal with arrow keys
 *
 */
void	move_fractal(int keydata, t_fractal *fractal)
{
	if (keydata == KEY_UP)
	{
		fractal->shift_y += fractal->offspeed;
		fractal_render(fractal);
	}
	else if (keydata == KEY_DOWN)
	{
		fractal->shift_y -= fractal->offspeed;
		fractal_render(fractal);
	}
	else if (keydata == KEY_LEFT)
	{
		fractal->shift_x -= fractal->offspeed;
		fractal_render(fractal);
	}
	else if (keydata == KEY_RIGHT)
	{
		fractal->shift_x += fractal->offspeed;
		fractal_render(fractal);
	}
}

/**
 * Gets a random color from my list of colors: hexcolors[]
 *
*/

static uint32_t	get_random_color(void)
{
	return (g_hexcolors[randomize(0, NUM_COLORS - 1)]);
}

/**
 *   Shaffle color palette 
 *
 */

void	shuffle_colors(int keydata, t_fractal *fractal)
{
	if (keydata == KEY_E)
	{
		fractal->colors[0] = get_random_color();
		fractal->colors[1] = get_random_color();
		fractal->colors[2] = get_random_color();
		ft_printf("\033[1;32m=>\033[0m\033[1;34m Shaffling colors:"
				"\033[0m\n"
				"#%x\n"
				"#%x\n"
				"#%x\n",
				fractal->colors[0],
				fractal->colors[1],
				fractal->colors[2]);
		fractal_render(fractal);
		return ;
	}
}