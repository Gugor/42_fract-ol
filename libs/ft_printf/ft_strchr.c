/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:51:02 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/08 19:54:01 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	ch;
	int				i;

	str = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	return (NULL);
}
