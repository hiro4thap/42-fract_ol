/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:05:19 by hiono             #+#    #+#             */
/*   Updated: 2024/03/31 19:50:32 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void fractol(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;

	i = 5;
	j = 5;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (i < 25)
	{
		j = 5;
		while (j < 25)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 0);
	mlx_loop(mlx);
}

int main(void)
{
	fractol();
	return (1);
}
