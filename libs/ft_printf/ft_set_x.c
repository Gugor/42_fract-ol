/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:20:54 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/22 16:42:50 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_printhex(unsigned int num, int count)
{
	char	*set;

	set = "0123456789abcdef";
	if (num > 0)
	{
		count = ft_printhex(num / 16, ++count);
		if (count == -1)
			return (-1);
		if (write(1, set + (num % 16), 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_set_x(va_list args, char flag)
{
	unsigned int	arg;
	int				i;

	if (flag != 'x')
		return (0);
	i = 0;
	arg = va_arg(args, unsigned int);
	if (arg == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (i + 1);
	}
	i = ft_printhex(arg, i);
	return (i);
}
