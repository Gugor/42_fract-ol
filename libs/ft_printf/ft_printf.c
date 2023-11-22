/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:22:36 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/16 16:41:08 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_is_strformat(const char first, const char second)
{
	char	*set;

	set = "csdpiuxX%";
	if (('%' == first) && ft_strchr(set, second))
		return (1);
	else
		return (0);
}

int	ft_set_format(char *format, va_list args)
{
	char	flag;
	int		result;

	flag = *(format + 1);
	result = 0;
	result += ft_set_c(args, flag);
	result += ft_set_s(args, flag);
	result += ft_set_d(args, flag);
	result += ft_set_i(args, flag);
	result += ft_set_u(args, flag);
	result += ft_set_x(args, flag);
	result += ft_set_xx(args, flag);
	result += ft_set_per(flag);
	result += ft_set_p(args, flag);
	if (result == -1)
		return (-1);
	if (result == -2)
		return (-2);
	return (result);
}

static int	ft_print_format(char *format, va_list args, int i)
{
	int		count;

	count = 0;
	while (*format)
	{
		if (!ft_is_strformat(*format, *(format + 1)))
		{
			if (write(1, format, 1) == -1)
				return (-1);
			format++;
			i++;
		}
		else
		{
			count = ft_set_format(format, args);
			if (count == -1)
				return (-1);
			if (count == -2)
				i = 0;
			else
				i += count;
			format += 2;
		}
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	i = ft_print_format((char *)format, args, i);
	va_end(args);
	return (i);
}
