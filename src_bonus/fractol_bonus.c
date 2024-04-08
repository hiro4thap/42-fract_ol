/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:55:32 by hiono             #+#    #+#             */
/*   Updated: 2024/04/08 17:23:10 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_vars	init_mlx(char **av)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bpp,
			&vars.img.line_length, &vars.img.endian);
	vars.x_min = -2.0;
	vars.x_max = 2.0;
	vars.y_min = -2.0;
	vars.y_max = 2.0;
	vars.zoom = 1.0;
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		vars.fractal_type = 1;
	else if (!ft_strncmp(av[1], "julia", 6))
	{
		vars.fractal_type = 2;
		vars.julia_x = atodb(av[2]);
		vars.julia_y = atodb(av[3]);
	}
	else if (!ft_strncmp(av[1], "burningships", 13))
		vars.fractal_type = 3;
	return (vars);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (!is_arg_valid(ac, av))
	{
		ft_printf(MSG_INVALID_ARG);
		ft_printf(MSG_ARG_MANDEBBROT);
		ft_printf(MSG_ARG_JULIA);
		return (1);
	}
	vars = init_mlx(av);
	fractal(vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, free_mlx, &vars);
	mlx_loop(vars.mlx);
	return (1);
}
