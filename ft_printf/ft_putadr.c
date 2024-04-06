/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:46:48 by hiono             #+#    #+#             */
/*   Updated: 2024/03/12 14:05:35 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr(unsigned long ul)
{
	int				i;
	char			*charset;

	i = 0;
	charset = "0123456789abcdef";
	if (0 < ul / 16)
		i = ft_putadr(ul / 16);
	if (i == 0)
	{
		write(1, "0x", 2);
		i += 2;
	}
	ft_putchar(charset[ul % 16]);
	i++;
	return (i);
}
