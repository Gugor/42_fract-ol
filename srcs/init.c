/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:58 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/21 17:06:35 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "events.h"
#include <X11/X.h>
/**
 * Fractal data init
 *
 */
void data_init(t_fractal *fractal)
{
	fractal->definition = 64;
	fractal->colors[0] = COLOR_WHITE;
	fractal->colors[1] = COLOR_JASPER;
	fractal->colors[2] = COLOR_PALE_PINK;
	fractal->zoom = 1.0;
	fractal->limit = 4.0; 
	fractal->offspeed = 0.01;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
}
/**
 * Let listen to events
 * void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)

 */
static void events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, 2, KeyPressMask, handle_key, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, scrollmouse, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask, close_fractol, fractal);
}

static void malloc_error()
{
	perror("Memory allocation error");
	return ;
} 

/**
 * We init our fractal
 *
 */
void fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, fractal->title, 1);
	if (fractal->mlx == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}
	fractal->mlx_win = mlx_new_window(fractal->mlx, WIN_WIDTH, WIN_HEIGHT, fractal->title);
	if (fractal->mlx_win == NULL)
	{
		malloc_error();
		ft_terminate(fractal);
	}
	fractal->img.img = mlx_new_image(fractal->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (fractal->img.img == NULL)
	{
		malloc_error();
		ft_terminate(fractal);
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	events_init(fractal); 
	data_init(fractal); 
}
