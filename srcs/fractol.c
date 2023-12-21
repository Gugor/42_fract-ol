/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:37 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/21 17:29:31 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/ft_printf.h"
#include "../includes/libft.h"

const uint32_t  g_hexcolors[] = {
    0x000000, 0xFFFFFF, 0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF,
    0x00FFFF, 0xFFA500, 0x800080, 0xFFC0CB, 0xA52A2A, 0x808080, 0x3a405a,
    0xaec5eb, 0xf9dec9, 0xe9afa3, 0x685044, 0x11151c, 0x212d40, 0x364156,
    0x7d4e57, 0xd66853};

int32_t	main(int argc, char **argv)
{
	t_fractal fractal;
	set_seed();

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
			|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.title = argv[1];
		if (argc == 4)
		{
			fractal.c.x = ft_atodb(argv[2]); 
			if (!argv[3])
				ft_printf("imaginary not found\n");
			fractal.c.y = ft_atodb(argv[3]);
		}
		ft_printf("\n\033[1;32m=>\033[1;0m \033[1;37mItitializing fractal \033[1;36m%s set\033[0m...\033[1;m\n", fractal.title);
		fractal_init(&fractal);
		ft_printf("\033[1;32m=>\033[1;0m \033[1;37mRedenring fractal...\033[1;m\n");
		fractal_render(&fractal); 
		ft_printf("\033[1;32m=>\033[1;0m \033[1;37mStaritng loop...\033[1;m\n\n");
		mlx_loop(fractal.mlx);
	}
	else
		ft_printf(":: Incorrect Input\n Usage examples:\n  ./fractol \"mandelbrot\"\n./fractol \"julia\" <value1> <value2>");
    return (EXIT_SUCCESS);
}
