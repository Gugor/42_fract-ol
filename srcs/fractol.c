/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:59:37 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/20 12:59:42 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/ft_printf.h"
#include "../includes/libft.h"

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
    mlx_terminate(fractal.mlx);

    return (EXIT_SUCCESS);
}
