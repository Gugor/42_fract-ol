/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:54:06 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/22 16:40:55 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_free_d(char *arg)
{
	if (arg)
		free(arg);
	return (-1);
}

int	ft_set_d(va_list args, char flag)
{
	char	*arg;
	int		tmp;
	int		i;

	if (flag != 'd')
		return (0);
	i = 0;
	tmp = va_arg(args, int);
	arg = ft_itoa(tmp);
	if (!arg)
		return (-1);
	while (*(arg + i))
	{
		if (write(1, arg + i, 1) == -1)
			return (ft_free_d(arg));
		i++;
	}
	if (arg)
		free(arg);
	return (i);
}
