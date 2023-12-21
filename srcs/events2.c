/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:09 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/20 16:26:30 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Change the precition of the fractal rendered
 *
 */
static void	change_definition(mlx_key_data_t keydata, void* param)
{
	t_fractal *fractal;
	int definition;

	fractal = (t_fractal *)param;
	definition = 50;
	if (keydata.key == MLX_KEY_PERIOD && keydata.action == MLX_PRESS)
	{
		ft_printf("\033[1;32m=>\033[0m Keypressed: \033[1;34m%d\033[0m\n",keydata.key);
		ft_printf(" \033[1;34m::\033[0m Changing definition from \033[1;31m%d\033[0m to \033[1;31m%d\033[0m\n", fractal->definition, fractal->definition + definition);
		fractal->definition += definition;
		fractal_render(fractal);
	}
	if(keydata.key == MLX_KEY_COMMA && keydata.action == MLX_PRESS)
	{
		ft_printf("\033[1;32m=>\033[0m Keypressed: \033[1;34m%d\033[0m\n",keydata.key);
		ft_printf(" \033[1;34m::\033[0m Changing definition from \033[1;31m%d\033[0m to \033[1;31m%d\033[0m\n", fractal->definition, fractal->definition - definition);
		fractal->definition -= definition;
		fractal_render(fractal);
	}
	return ;
}

/**
 *  Handel key
 *
 */
void	handle_key(mlx_key_data_t keydata, void* param)
{
	t_fractal *fractal;

	fractal = (t_fractal *)param;
	move_fractal(keydata, fractal);
	shuffle_colors(keydata, fractal);
	change_definition(keydata, fractal);
	close_fractol(keydata, fractal);

}

