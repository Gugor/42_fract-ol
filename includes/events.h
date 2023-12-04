#ifndef EVENTS_H
# define EVENTS_H

// Funtion Events
void scrollmouse(double xdelta, double ydelta, void *param);
void handle_key(mlx_key_data_t keydata, void* param);
void close_fractol(void *param);
#endif
