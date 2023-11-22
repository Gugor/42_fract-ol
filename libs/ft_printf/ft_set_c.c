/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:36:56 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/16 13:55:28 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_set_c(va_list args, char flag)
{
	char	arg;

	if (flag != 'c')
		return (0);
	arg = va_arg(args, int);
	if (write(1, &arg, 1) == -1)
		return (-1);
	return (1);
}
