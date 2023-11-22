/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:08:26 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/22 16:37:28 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	get_numsize_signed(int *num, int *neg)
{
	int	size;
	int	n;

	size = 0;
	if (*num < 0)
	{
		*neg = 1;
		*num *= -1;
	}
	n = *num;
	if (n == 0)
		return (++size);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	if (*neg == 1)
		size++;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		is_neg;
	int		size;

	is_neg = 0;
	size = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = get_numsize_signed(&n, &is_neg);
	if (n == 0)
		return (ft_strdup("0"));
	num = (char *)ft_calloc(size + 1, sizeof(char));
	if (!num)
		return (NULL);
	while (size > 0)
	{
		num[--size] = n % 10 + 48;
		n /= 10;
	}
	if (is_neg)
		num[0] = '-';
	return (num);
}
