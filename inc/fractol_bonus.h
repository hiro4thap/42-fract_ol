/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:05:21 by hiono             #+#    #+#             */
/*   Updated: 2024/04/07 16:48:15 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define XK_ESC 53
# define ON_DESTROY 17

# define HEIGHT 800
# define WIDTH 800
# define ITR 40

# define C_WHITE 0x00ffffff
# define C_BLACK 0x00000000
# define C_BLUE 0x0012004c
# define C_YELLOW 0x00ffd966

# define MSG_INVALID_ARG "Arguments should be as follows for each set.\n"
# define MSG_ARG_MANDEBBROT "mandelbrot\n"
# define MSG_ARG_JULIA "julia [x] [y]\n"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
	double	zoom;
	int		fractal_type; //1:mandelbrot 2:julia
	double	julia_x;
	double	julia_y;
}				t_vars;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_scale
{
	double	max;
	double	min;
	double	old_max;
	double	old_min;
}				t_scale;

double		scale(double value, double new_max,	double new_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		atodb(char *str);
int			free_mlx(t_vars *vars);
int			mouse_hook(int mousesym, int x, int y, t_vars *vars);
int			key_hook(int keysym, t_vars *vars);
int			is_double(char *str);
int			is_arg_valid(int ac, char *av[]);
void		fractal(t_vars vars);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif
