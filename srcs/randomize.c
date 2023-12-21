/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:00:42 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/20 13:00:46 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Set the seed to randomize
 */
void set_seed()
{
	srand(time(NULL));
}

/**
 * Get a random number
 */
int randomize(int min, int max) 
{
    return (min + rand() % (max - min + 1));
}
