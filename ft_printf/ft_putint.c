/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:47:23 by hiono             #+#    #+#             */
/*   Updated: 2024/03/12 14:06:03 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int n)
{
	int		i;
	char	*istr;

	i = 0;
	istr = ft_itoa(n);
	ft_putstr(istr);
	i = ft_strlen(istr);
	free(istr);
	return (i);
}
