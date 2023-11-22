/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:58:23 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/16 17:30:51 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_set_i(va_list args, char flag)
{
	int		i;

	if (flag != 'i')
		return (0);
	i = ft_set_d(args, 'd');
	return (i);
}
