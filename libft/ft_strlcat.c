/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:52:03 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 21:07:45 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t i, size_t j)
{
	if (i <= j)
	{
		return (i);
	}
	return (j);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	sl;
	size_t	dl;

	sl = ft_strlen(src);
	dl = ft_strlen(dest);
	i = 0;
	if (size == 0)
	{
		return (sl);
	}
	while (src[i] && dl + i < size - 1)
	{
		dest[dl + i] = src[i];
		i++;
	}
	dest[dl + i] = '\0';
	return (ft_min(dl, size) + sl);
}
