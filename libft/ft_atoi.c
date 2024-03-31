/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:31:52 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 23:18:41 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	pn;
	int	res;

	pn = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
	{
		str++;
	}
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		pn *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (pn * res);
}
