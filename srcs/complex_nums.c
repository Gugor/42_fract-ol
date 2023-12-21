/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:58:21 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/20 13:20:48 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Adds two complex numbers
 *
 */
t_comple	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/**
 * Squarer two complex numbers 
 *
 */
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

/**
 * Print a complex number type
 * @dev puropuses
 */
void	print_complex(t_complex z)
{
	t_complex	a;
	int			i;

	a = z;
	i = 100;
	while (i > 0)
	{
		printf("real = %.f , imaginary = %.f\n ", a.x, a.y);
		a = sum_complex(square_complex(a), a);
		i--;
	}
}
