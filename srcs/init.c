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
	fractal->offspeed = 0.1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
}
/**
 * Let listen to events
 *
 *
static void events_init(t_fractal *fractal)
{
	//mlx_key_hook(fractal->mlx, &handle_key, fractal);
	//mlx_scroll_hook(fractal->mlx, &scrollmouse, fractal);
}*/

static void malloc_error()
{
	perror("Memory allocation error");
	exit(EXIT_FAILURE);
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
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img->img = mlx_new_image(fractal->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (fractal->img->img)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img->pixels = mlx_get_data_addr(fractal->img->img,
			&fractal->img->bpp,
			&fractal->img->line_len,
			&fractal->img->endian);
	//events_init(fractal); 
	data_init(fractal); 
}
