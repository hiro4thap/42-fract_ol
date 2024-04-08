/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:54:47 by hiono             #+#    #+#             */
/*   Updated: 2024/04/08 17:43:01 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

int	free_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_printf("Memory cleared.\n");
	exit(1);
	return (1);
}

void	zoom_in(t_vars *vars, int x, int y)
{
	double	sx;
	double	sy;

	vars->zoom *= ZOOM_IN;
	sx = scale(x, vars->x_max, vars->x_min, WIDTH);
	sy = scale(y, vars->y_max, vars->y_min, HEIGHT);
	vars->x_min = vars->x_min * ZOOM_IN + sx * (1 - ZOOM_IN);
	vars->x_max = vars->x_max * ZOOM_IN + sx * (1 - ZOOM_IN);
	vars->y_min = vars->y_min * ZOOM_IN + sy * (1 - ZOOM_IN);
	vars->y_max = vars->y_max * ZOOM_IN + sy * (1 - ZOOM_IN);
}

void	zoom_out(t_vars *vars, int x, int y)
{
	double	sx;
	double	sy;

	vars->zoom *= ZOOM_OUT;
	sx = scale(x, vars->x_max, vars->x_min, WIDTH);
	sy = scale(y, vars->y_max, vars->y_min, HEIGHT);
	vars->x_min = vars->x_min * ZOOM_OUT + sx * (1 - ZOOM_OUT);
	vars->x_max = vars->x_max * ZOOM_OUT + sx * (1 - ZOOM_OUT);
	vars->y_min = vars->y_min * ZOOM_OUT + sy * (1 - ZOOM_OUT);
	vars->y_max = vars->y_max * ZOOM_OUT + sy * (1 - ZOOM_OUT);
}

int	mouse_hook(int mousesym, int x, int y, t_vars *vars)
{
	ft_printf("Mouse position x: %d y: %d oeration: %d\n", x, y, mousesym);
	if (mousesym == 1 | mousesym == 2 | mousesym == 3)
		return (1);
	if (mousesym == 4)
		zoom_in(vars, x, y);
	else if (mousesym == 5)
		zoom_out(vars, x, y);
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_length, &vars->img.endian);
	fractal(*vars);
	return (1);
}

int	key_hook(int keysym, t_vars *vars)
{
	ft_printf("Pressed %d\n", keysym);
	if (keysym == XK_ESC)
		free_mlx(vars);
	else if (keysym == XK_LEFT)
	{
		vars->x_min -= 0.2 * vars->zoom;
		vars->x_max -= 0.2 * vars->zoom;
	}
	else if (keysym == XK_RIGHT)
	{
		vars->x_min += 0.2 * vars->zoom;
		vars->x_max += 0.2 * vars->zoom;
	}
	else if (keysym == XK_DOWN)
	{
		vars->y_min += 0.2 * vars->zoom;
		vars->y_max += 0.2 * vars->zoom;
	}
	else if (keysym == XK_UP)
	{
		vars->y_min -= 0.2 * vars->zoom;
		vars->y_max -= 0.2 * vars->zoom;
	}
	fractal(*vars);
	return (1);
}
