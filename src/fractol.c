/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:05:19 by hiono             #+#    #+#             */
/*   Updated: 2024/04/05 16:56:36 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	put_mandelbrot(t_vars vars, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	c;

	z.x = scale(x, 1.0, -2.0, HEIGHT, 0);
	z.y = scale(y, -1.5, 1.5, WIDTH, 0);
	c.x = z.x;
	c.y = z.y;
	i = 0;
	while(i < ITR)
	{
		z = sum_complex(square_complex(z), c);
		if (pow(z.x, 2) + pow(z.y, 2) > 4)
		{
			my_mlx_pixel_put(&vars.img, x, y, scale(i, C_YELLOW, C_BLUE, ITR, 0));
			return;
		}
		i++;
	}
	my_mlx_pixel_put(&vars.img, x, y, C_BLACK);
}

void	put_julia(t_vars vars, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	c;

	z.x = scale(x, 1.5, -1.5, HEIGHT, 0);
	z.y = scale(y, -1.5, 1.5, WIDTH, 0);
	c.x = vars.julia_x;
	c.y = vars.julia_y;
	i = 0;
	while(i < ITR)
	{
		z = sum_complex(square_complex(z), c);
		if (pow(z.x, 2) + pow(z.y, 2) > 4)
		{
			my_mlx_pixel_put(&vars.img, x, y, scale(i, C_YELLOW, C_BLUE, ITR, 0));
			return;
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
				put_mandelbrot(vars, x, y);
			else if (vars.fractal_type == 2)
				put_julia(vars, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
}

t_vars	init_mlx(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bpp,
					&vars.img.line_length,&vars.img.endian);
	vars.fractal_type = 1;
	vars.zoom = 1.0;
	return (vars);
}


int main(int ac, char *av[])
{
	t_vars	vars;

	(void) av;
	if (ac != 1 && ac != 3)
	{
		printf(INVALID_INPUT);
		return (1);
	}
	vars = init_mlx();
	if (ac == 3)
	{
		vars.fractal_type = 2;
		vars.julia_x = atodb(av[1]);
		vars.julia_y = atodb(av[2]);
	}
	fractal(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (1);
}
