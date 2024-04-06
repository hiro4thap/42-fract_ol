/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthxl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:48:40 by hiono             #+#    #+#             */
/*   Updated: 2024/03/12 14:05:57 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthxl(unsigned int n)
{
	int		i;
	long	nb;
	char	*charset;

	i = 0;
	nb = n;
	charset = "0123456789abcdef";
	if (0 < nb / 16)
		i = ft_puthxl(nb / 16);
	ft_putchar(charset[nb % 16]);
	i++;
	return (i);
}
