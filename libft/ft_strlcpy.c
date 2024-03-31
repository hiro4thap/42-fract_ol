/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:27:41 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 21:08:57 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lsrc;

	i = 0;
	lsrc = ft_strlen(src);
	if (size == 0)
	{
		return (lsrc);
	}
	while (i < size - 1 && i < lsrc)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lsrc);
}
