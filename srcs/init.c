#include "fractol.h"
#include "events.h"
/**
 * Fractal data init
 *
 */
void data_init(t_fractal *fractal)
{
	fractal->definition = 64;
	fractal->colors[0] = COLOR_WHITE;
	fractal->colors[1] = COLOR_JASPER;
	fractal->colors[2] = COLOR_PALE_PINK;
	fractal->zoom = 1.0;
	fractal->limit = 4.0; 
	fractal->offspeed = 0.1;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
}
/**
 * Let listen to events
 *
 */
static void events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx, &handle_key, fractal);
	mlx_scroll_hook(fractal->mlx, &scrollmouse, fractal);
}

/**
 * We init our fractal
 *
 */
void fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, fractal->title, 1);
	if (fractal->mlx == NULL)
	{
		mlx_terminate(fractal->mlx);
		exit(EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->mlx, WIN_WIDTH, WIN_HEIGHT);
	ft_memset(fractal->img->pixels, WHITE, 
			fractal->img->width * fractal->img->height * BPP);	
	mlx_image_to_window(fractal->mlx, fractal->img, fractal->shift_x, fractal->shift_y);

	events_init(fractal); 
	data_init(fractal); 
}
