/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:55:18 by hiono             #+#    #+#             */
/*   Updated: 2024/04/07 16:55:25 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

double	scale(double value, double new_max, double new_min, double old_max)
{
	return ((value * (new_max - new_min) / old_max) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = pow(z.x, 2) - pow(z.y, 2);
	res.y = 2 * z.x * z.y;
	return (res);
}

double	atodb(char *str)
{
	double	res;
	int		i;
	int		sign;

	if (!*str)
		return (0.0);
	res = 0.0;
	i = -1;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
		res = res * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
		res += (*str++ - '0') * pow(10, i--);
	return (sign * res);
}
