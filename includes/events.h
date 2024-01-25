/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:01:39 by hmontoya          #+#    #+#             */
/*   Updated: 2024/01/25 18:13:22 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#ifndef EVENTS_H
# define EVENTS_H
// Macros
# define KEY_ESCAPE 53
# define KEY_UP     126
# define KEY_DOWN   125
# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_E      14
# define KEY_PERIOD 47
# define KEY_COMMA  43 
// Funtion Events
int scrollmouse(int button, int x, int y, void *param);
int handle_key(int keysim, void *param);
int close_fractol(int keysim, void *param);
#endif
