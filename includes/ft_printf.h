/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:13:11 by hmontoya          #+#    #+#             */
/*   Updated: 2023/07/06 18:14:15 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_num_flags(const char *format);
int		ft_is_strformat(const char first, const char second);
int		ft_set_format(char *format, va_list args);
int		ft_set_c(va_list args, char flag);
int		ft_set_s(va_list args, char flag);
int		ft_set_d(va_list args, char flag);
int		ft_set_i(va_list args, char flag);
int		ft_set_u(va_list args, char flag);
int		ft_set_x(va_list args, char flag);
int		ft_set_xx(va_list args, char flag);
int		ft_set_p(va_list args, char flag);
int		ft_set_per(char flag);
#endif
