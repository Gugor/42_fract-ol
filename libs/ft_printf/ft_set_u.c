/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:04:26 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/22 16:42:09 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	get_numsize(unsigned int num)
{
	int	size;

	size = 0;
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

static char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		size;

	size = 0;
	if (n == 0)
		return (ft_strdup("0"));
	size = get_numsize(n);
	num = (char *)ft_calloc(size + 1, sizeof(char));
	if (!num)
		return (NULL);
	while (size > 0)
	{
		num[--size] = n % 10 + 48;
		n /= 10;
	}
	return (num);
}

int	ft_free(char *arg)
{
	if (arg)
		free(arg);
	return (-1);
}

int	ft_set_u(va_list args, char flag)
{
	char			*arg;
	unsigned int	tmp;
	int				i;
	int				rs;

	if (flag != 'u')
		return (0);
	i = 0;
	rs = 0;
	tmp = va_arg(args, unsigned int);
	arg = ft_utoa(tmp);
	if (!arg)
		return (-1);
	while (*(arg + i))
	{
		rs = write(1, arg + i, 1);
		if (rs == -1)
			return (ft_free(arg));
		i++;
	}
	if (arg)
		free(arg);
	return (i);
}
