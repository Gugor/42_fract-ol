#include "../includes/fractol.h"
#include "../includes/ft_printf.h"

void error_handler(int argc, char *ftype)
{
	if (!ftype || !ftype[0])
	{
		ft_printf("No fractal type specified...\n");
		ft_printf("Default type will be used instead.\n");
	}
	if (argc < 1 || argc > 2)
	{
		perror("wrong number of arguments");
		ft_printf("Wrong number of arguments");
		ft_printf("Usage: ./fractol [optional: mandelbort | juila]");
		exit(1);
	}
}

int main(int argc, char **argsv)
{
	error_handler(argc, argsv[1]);
	void *mlx;
	void *mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return (0);
}
