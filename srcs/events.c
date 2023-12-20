/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:09 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/20 12:59:15 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

const uint32_t hexcolors[] = {
     0x000000, 0xFFFFFF, 0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF, 0x00FFFF,
     0xFFA500, 0x800080, 0xFFC0CB, 0xA52A2A, 0x808080, 0x3a405a, 0xaec5eb, 0xf9dec9,
     0xe9afa3, 0x685044, 0x11151c, 0x212d40, 0x364156, 0x7d4e57, 0xd66853
 };

/**
 * Close Fractol
 *
 */
void close_fractol(mlx_key_data_t keydata, t_fractal *fractal)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_terminate(fractal->mlx);
}

/**
 * Zoom in out fractal with mouse wheel
 *
 */
void scrollmouse(double xdelta, double ydelta, void *param)
{
	t_fractal *fractal;
	double mod = 0.05;
	double oldzoom;
	int32_t mouse_x;
	int32_t mouse_y;

	fractal = (t_fractal *)param;
	oldzoom = fractal->zoom;
	xdelta = 0.0;
	mlx_get_mouse_pos(fractal->mlx, &mouse_x, &mouse_y);
	printf(":: Mouse scrolling..\n");
	printf(":: MouseX: %d | MouseY: %d\n", mouse_x, mouse_y);
	/**
	 *		_______800_______
	 *		|	| 100		|
	 *		|––	X 			|
	 * 800	|200			|
	 *		|				|
	 *		|				|
	 *		_________________
	 *		side_ratio_x = (mouse - (width / 2)) / width
	 *		pixels_distance = (width / oldzoom) - (width / newzoom)
	 */
	if (ydelta > 0)
	{
		fractal->zoom *= 1.0 - mod; 
		zoom_to_mouse(mouse_x, mouse_y, fractal);
		fractal->offspeed *= 1.0 - mod;
		fractal_render(fractal);
	}
	if (ydelta < 0)
	{
		fractal->zoom *= 1.0 + mod; 
		zoom_to_mouse(mouse_x, mouse_y, fractal);
		fractal->offspeed *= 1.0 + mod;
		fractal_render(fractal);
	}
}

/**
 * Move the fractal with arrow keys
 *
 */
static void move_fractal(mlx_key_data_t keydata, t_fractal *fractal)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		fractal->shift_y += fractal->offspeed;
		fractal_render(fractal);
		return ;
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		fractal->shift_y -= fractal->offspeed;
		fractal_render(fractal);
		return ;
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		fractal->shift_x -= fractal->offspeed;
		fractal_render(fractal);
		return ;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		fractal->shift_x += fractal->offspeed;
		fractal_render(fractal);
		return ;
	}
}

/**
 * Gets a random color from my list of colors: hexcolors[]
 *
 */
static uint32_t get_random_color()
{
	return (hexcolors[randomize(0,NUM_COLORS-1)]);
}

/**
 *   Shaffle color palette 
 *
 */
static void shuffle_colors(mlx_key_data_t keydata, t_fractal *fractal)
{

	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	{
		fractal->colors[0] = get_random_color();
		fractal->colors[1] = get_random_color();
		fractal->colors[2] = get_random_color();
		ft_printf("\033[1;32m=>\033[0m Shuffling colors: min(\033[1;37m%x\033[0m), max(\033[1;37m%x\033[0m), shape(\033[1;37m%x\033[0m)\n", fractal->colors[0], fractal->colors[1], fractal->colors[2]);
		fractal_render(fractal);
		return ;
	}
}

/**
 * Change the precition of the fractal rendered
 *
 */
static void change_definition(mlx_key_data_t keydata, void* param)
{
	t_fractal *fractal;
	int definition;

	fractal = (t_fractal *)param;
	definition = 50;
	if (keydata.key == MLX_KEY_PERIOD && keydata.action == MLX_PRESS)
	{
		ft_printf("\033[1;32m=>\033[0m Keypressed: \033[1;34m%d\033[0m\n",keydata.key);
		printf(" \033[1;34m::\033[0m Changing definition from \033[1;31m%d\033[0m to \033[1;31m%d\033[0m\n", fractal->definition, fractal->definition + definition);
		fractal->definition += definition;
		fractal_render(fractal);
	}
	if(keydata.key == MLX_KEY_COMMA && keydata.action == MLX_PRESS)
	{
		ft_printf("\033[1;32m=>\033[0m Keypressed: \033[1;34m%d\033[0m\n",keydata.key);
		printf(" \033[1;34m::\033[0m Changing definition from \033[1;31m%d\033[0m to \033[1;31m%d\033[0m\n", fractal->definition, fractal->definition - definition);
		fractal->definition -= definition;
		fractal_render(fractal);
	}
	return ;
}
/**
 *  Handel key
 *
 */
void handle_key(mlx_key_data_t keydata, void* param)
{
	t_fractal *fractal;

	fractal = (t_fractal *)param;
	move_fractal(keydata, fractal);
	shuffle_colors(keydata, fractal);
	change_definition(keydata, fractal);
	close_fractol(keydata, fractal);

}

