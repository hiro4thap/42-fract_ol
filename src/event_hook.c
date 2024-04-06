/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:13:56 by hiono             #+#    #+#             */
/*   Updated: 2024/04/06 15:43:53 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	free_mlx(t_vars *vars)
{
	ft_printf("closed window, clearing buffers.\n");
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_printf("now cleared.\n");
	exit(1);
	return (1);
}

int	mouse_hook(int mousesym, int x, int y, t_vars *vars)
{
	(void) vars;
	ft_printf("Mouse position x: %d y: %d oeration: %d\n", x, y, mousesym);
	if (mousesym == 1 | mousesym == 2 | mousesym == 3)
		return (1);
	if (mousesym == 4)
		vars->zoom *= 1.10;
	else if (mousesym == 5)
		vars->zoom /= 1.10;
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_length, &vars->img.endian);
	//TODO:bonus add x/y to centerize the mouse pointer
	fractal(*vars);
	return (1);
}

//TODO:handle closing window by clicking
//TODO:remove printf
int	key_hook(int keysym, t_vars *vars)
{
	ft_printf("Pressed %d\n", keysym);
	if (keysym == XK_ESC)
		free_mlx(vars);
	return (1);
}
