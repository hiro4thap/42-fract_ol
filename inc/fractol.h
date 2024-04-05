/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:05:21 by hiono             #+#    #+#             */
/*   Updated: 2024/04/05 19:38:42 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define XK_ESC 53

# define HEIGHT 800
# define WIDTH 800
# define ITR 40

# define C_BLACK 0x00000000
# define C_BLUE 0x0012004c
# define C_YELLOW 0x00ffd966
# define ON_DESTROY 17

//TOOD:set message
# define INVALID_INPUT "input should be..."

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

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
	//mlx
	void	*mlx;
	void	*win;
	//img
	t_img	img;
	//params
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

//math_utils
double		scale(double value, double new_max, double new_min, double old_max, double old_min);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		atodb(char *str);

//event_hook
int			free_mlx(t_vars *vars);
int			mouse_hook(int mousesym, int x, int y, t_vars *vars);
int			key_hook(int keysym, t_vars *vars);

//fractol
void		fractal(t_vars vars);

#endif
