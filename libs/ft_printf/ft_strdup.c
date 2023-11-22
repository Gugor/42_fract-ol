/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:42:41 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/09 16:40:35 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*dup;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)malloc(len + 1 * sizeof(char));
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = (char)s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
