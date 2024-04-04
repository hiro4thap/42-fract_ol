/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:05:19 by hiono             #+#    #+#             */
/*   Updated: 2024/04/04 19:54:16 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

//TODO:handle closing window by clicking
//TODO:remove printf
//TODO:need to sleep?
int key_hook(int keysym, t_vars *vars)
{
    printf("Pressed %d\n", keysym);
	if (keysym == XK_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(1);
	}
    sleep(1);
    return (1);
}

double	scale(double value, double new_max, double new_min, double old_max, double old_min)
{
	return (((value - old_min) * (new_max - new_min) / (old_max - old_min)) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex res;

	res.x = pow(z.x, 2) - pow(z.y, 2);
	res.y = 2 * z.x * z.y;
	return (res);
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

int	mouse_hook(int mousesym, int x, int y, t_vars *vars)
{
	(void) vars;
	printf("Mouse position x: %d y: %d oeration: %d\n", x, y, mousesym);
	if (mousesym == 1 | mousesym == 2 | mousesym == 3)
		return (1);
	if (mousesym == 4)
		vars->zoom *= 1.05;
	else if (mousesym == 5)
		vars->zoom *= 0.95;
	//TODO:replace img with new one
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
					&vars->img.line_length,&vars->img.endian);
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			//TODO:bonus add x/y to centerize the mouse pointer
			fractal(*vars);
			y++;
		}
		x++;
	}
	return (1);
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

double	atodb(char *str)
{
	double	res;
	int		i;
	int		sign;

	if(!*str)
		return 0.0;
	res = 0.0;
	i = -1;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str)
	{
		res += (*str - '0') * pow(10, i);
		i--;
		str++;
	}
	return (sign * res);
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
