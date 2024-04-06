/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthxu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:51:05 by hiono             #+#    #+#             */
/*   Updated: 2024/03/12 14:05:25 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthxu(unsigned int n)
{
	int		i;
	long	nb;
	char	*charset;

	i = 0;
	nb = n;
	charset = "0123456789ABCDEF";
	if (0 < nb / 16)
		i = ft_puthxu(nb / 16);
	ft_putchar(charset[nb % 16]);
	i++;
	return (i);
}
