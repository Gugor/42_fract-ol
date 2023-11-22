/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:31:06 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/16 14:02:52 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_set_s(va_list args, char flag)
{
	char	*arg;
	int		i;

	if (flag != 's')
		return (0);
	i = 0;
	arg = va_arg(args, char *);
	if (!arg)
		arg = "(null)";
	while (*(arg + i))
	{
		if (write(1, arg + i, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
