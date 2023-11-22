/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:18:35 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/22 16:35:41 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_printlonghex(unsigned long num, int count)
{
	char	*set;

	set = "0123456789abcdef";
	if (num > 0)
	{
		count = ft_printlonghex(num / 16, ++count);
		if (count == -1)
			return (-1);
		if (write(1, set + (num % 16), 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_set_p(va_list args, char flag)
{
	char			*ptr;
	unsigned long	arg;
	int				i;

	if (flag != 'p')
		return (0);
	ptr = "0x";
	i = 0;
	while (*ptr)
	{
		if (write(1, ptr, 1) == -1)
			return (-1);
		ptr++;
		i++;
	}
	arg = va_arg(args, unsigned long);
	if (arg == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (i + 1);
	}
	i = ft_printlonghex(arg, i);
	return (i);
}
