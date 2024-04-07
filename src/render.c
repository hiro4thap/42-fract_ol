/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:21:54 by hiono             #+#    #+#             */
/*   Updated: 2024/04/07 16:29:31 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	render_mandelbrot(t_vars vars, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	c;

	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(x, 2.0, -2.0, HEIGHT) * vars.zoom;
	c.y = scale(y, -2.0, 2.0, WIDTH) * vars.zoom;
	i = 0;
	while (i < ITR)
	{
		z = sum_complex(square_complex(z), c);
		if (pow(z.x, 2) + pow(z.y, 2) > 4)
		{
			my_mlx_pixel_put(&vars.img, x, y,
				scale(i, C_YELLOW, C_BLUE, ITR));
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&vars.img, x, y, C_BLACK);
}

void	render_julia(t_vars vars, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	c;

	z.x = scale(x, 1.5, -1.5, HEIGHT) * vars.zoom;
	z.y = scale(y, -1.5, 1.5, WIDTH) * vars.zoom;
	c.x = vars.julia_x;
	c.y = vars.julia_y;
	i = 0;
	while (i < ITR)
	{
		z = sum_complex(square_complex(z), c);
		if (pow(z.x, 2) + pow(z.y, 2) > 4)
		{
			my_mlx_pixel_put(&vars.img, x, y,
				scale(i, C_YELLOW, C_BLUE, ITR));
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&vars.img, x, y, C_BLACK);
}

void	fractal(t_vars vars)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			if (vars.fractal_type == 1)
				render_mandelbrot(vars, x, y);
			else if (vars.fractal_type == 2)
				render_julia(vars, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}
