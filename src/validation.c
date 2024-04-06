/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:53:12 by hiono             #+#    #+#             */
/*   Updated: 2024/04/06 20:10:42 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	is_double(char *str)
{
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	else if (*str == '.')
		str++;
	else
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	is_arg_valid(int ac, char *av[])
{
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		return (1);
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6)
		&& is_double(av[2]) && is_double(av[3]))
		return (1);
	return (0);
}
