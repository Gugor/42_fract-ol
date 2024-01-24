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
#include "events.h"

/**
 * Change the precition of the fractal rendered
 *
 */

static void	change_definition(int keydata, void* param)
{
	t_fractal *fractal;
	int definition;

	fractal = (t_fractal *)param;
	definition = 50;
	if (keydata == KEY_PERIOD)
	{
		ft_printf("\033[1;32m=>\033[0m Keypressed: \033[1;34m%d\033[0m\n",keydata);
		printf(" \033[1;34m::\033[0m Changing definition from \033[1;31m%d\033[0m to \033[1;31m%d\033[0m\n", fractal->definition, fractal->definition + definition);
		fractal->definition += definition;
		fractal_render(fractal);
	}
	if(keydata == KEY_COMMA)
	{
		ft_printf("\033[1;32m=>\033[0m Keypressed: \033[1;34m%d\033[0m\n",keydata);
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
int	handle_key(int keysim, void* param)
{
	t_fractal *fractal;

	//printf("[]-%d\n", keysim);
	fractal = (t_fractal *)param;
	close_fractol(keysim, fractal);
	move_fractal(keysim, fractal);
	shuffle_colors(keysim, fractal);
	change_definition(keysim, fractal);
	return (0);

}


