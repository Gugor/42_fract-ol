/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:01:39 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/20 13:01:44 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

// Funtion Events
void scrollmouse(double xdelta, double ydelta, void *param);
void handle_key(mlx_key_data_t keydata, void* param);
void close_fractol(void *param);
#endif
