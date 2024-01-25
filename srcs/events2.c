/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:09 by hmontoya          #+#    #+#             */
/*   Updated: 2024/01/25 19:23:43 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "events.h"

static void	print_definition(t_fractal *f, int keydata, int definition)
{
	ft_printf("\033[1;32m=>\033[0m Keypressed: \033[1;34m%d\033[0m\n",
		keydata);
	ft_printf(" \033[1;34m::\033[0m Changing definition from"
		" \033[1;31m%d\033[0m to \033[1;31m%d\033[0m\n",
		f->definition, f->definition + definition);
}

/**
 * Change the precition of the fractal rendered
 *
 */
static void	change_definition(int keydata, void *param)
{
	t_fractal	*f;
	int			definition;

	f = (t_fractal *)param;
	definition = 50;
	if (keydata == KEY_PERIOD)
	{
		print_definition(f, keydata, definition);
		f->definition += definition;
		fractal_render(f);
	}
	if (keydata == KEY_COMMA)
	{
		print_definition(f, keydata, definition);
		f->definition -= definition;
		fractal_render(f);
	}
	return ;
}

/**
 *  Handel key
 *
 */
int	handle_key(int keysim, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	close_fractol(keysim, fractal);
	move_fractal(keysim, fractal);
	shuffle_colors(keysim, fractal);
	change_definition(keysim, fractal);
	return (0);
}
