/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:58 by hmontoya          #+#    #+#             */
/*   Updated: 2024/01/25 19:49:08 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "events.h"
//#include <X11/X.h>
/**
 * Fractal data init
 *
 */
void	data_init(t_fractal *fractal)
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
 * void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask,
 * int (*f)(), void *param)
 */
static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, 2, 1L << 0, handle_key, fractal);
	mlx_hook(fractal->mlx_win, 4, 1L << 2, scrollmouse, fractal);
	mlx_hook(fractal->mlx_win, 17, 1L << 19, close_fractol, fractal);
}

static void	malloc_error(void)
{
	perror("Memory allocation error");
	return ;
}

/**
 * We init our fractal
 *
 */
void	fractal_init(t_fractal *f)
{
	f->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, f->title, 1);
	if (fractal->mlx == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}
	f->mlx_win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, f->title);
	if (f->mlx_win == NULL)
	{
		malloc_error();
		ft_terminate(f);
	}
	f->img.img = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (f->img.img == NULL)
	{
		malloc_error();
		ft_terminate(f);
	}
	f->img.pixels = mlx_get_data_addr(f->img.img,
			&f->img.bpp,
			&f->img.line_len,
			&f->img.endian);
	events_init(f);
	data_init(f);
}
