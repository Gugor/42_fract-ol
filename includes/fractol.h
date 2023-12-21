/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:03:03 by hmontoya          #+#    #+#             */
/*   Updated: 2023/12/20 13:03:11 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
# ifndef BPP
#  define BPP sizeof(int32_t)
# endif
# ifndef WIN_WIDTH
#  define WIN_WIDTH 800 
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 800 
# endif


#define COLOR_BLACK 		0x000000
#define COLOR_WHITE 		0xFFFFFF
#define COLOR_RED			0xFF0000
#define COLOR_GREEN 		0x00FF00
#define COLOR_BLUE			0x0000FF
#define COLOR_YELLOW		0xFFFF00
#define COLOR_MAGENTA		0xFF00FF
#define COLOR_CYAN			0x00FFFF
#define COLOR_ORANGE		0xFFA500
#define COLOR_PURPLE1		0x800080
#define COLOR_PINK			0xFFC0CB
#define COLOR_BROWN			0xA52A2A
#define COLOR_GRAY			0x808080
// 
#define COLOR_NAVY_BLUE		0x3a405a
#define COLOR_LIGHT_BLUE	0xaec5eb
#define COLOR_PEACH			0xf9dec9
#define COLOR_PALE_PINK		0xe9afa3
#define COLOR_BROWN1		0x685044
//
#define COLOR_RICH_BLACK	0x11151c
#define COLOR_PRUSSIAN_BLU	0x212d40
#define COLOR_CHARCOAL		0x364156 
#define COLOR_ROSE_TAUPE	0x7d4e57
#define COLOR_JASPER		0xd66853
//
#define COLOR_MELON         0xdaa89b
#define COLOR_ROSY_BROWN    0xae847e
#define COLOR_DARK_PURPLE   0x2c0e37
#define COLOR_PURPLE        0x690375
#define COLOR_MULBERRY      0xcb429f
//
#define COLOR_NYANZA           0xe5ffde
#define COLOR_ASH_GRAY         0xbbcbcb
#define COLOR_COOL_GRAY        0x9590a8
#define COLOR_ENGLISH_VIOLET   0x634b66
#define COLOR_LICORICE         0x18020c

// Dependencies
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// Globals
enum color_index {
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN,
    ORANGE,
    PURPLE1,
    PINK,
    BROWN,
    GRAY,
    NAVY_BLUE,
    LIGHT_BLUE,
    PEACH,
    PALE_PINK,
    BROWN1,
    RICH_BLACK,
    PRUSSIAN_BLU,
    CHARCOAL,
    ROSE_TAUPE,
    JASPER,
    NUM_COLORS
};

extern const uint32_t hexcolors[];

// Structs
typedef struct s_complex
{
	double x; // real number
	double y; // imaginary number i^2= -1
} t_complex;

typedef struct s_fractal
{	
	char	*title;
	mlx_t 	*mlx; 
	mlx_image_t	*img;
	double limit;
	int definition;
	int colors[4];
	double zoom;
	double offspeed;
    t_complex c;
	t_complex z;
	double shift_x;
	double shift_y;
} t_fractal;

// Functions

/* ... Init ...*/
void fractal_init(t_fractal *fractal);
/* ... Render ... */
void fractal_render(t_fractal *fractal);
void refresh_image(t_fractal *fractal);
/* ... Complex Numbers ... */
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);
void print_complex(t_complex z);
/* ... Math Utils ...*/
double scale_between(double unscaled, double min_limit, double max_limit, double        min,     double max);
void zoom_to_mouse(double x, double y, t_fractal *fractal);
/* ... Randomize ... */
void set_seed();
int randomize(int min, int max);
#endif
