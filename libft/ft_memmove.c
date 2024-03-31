/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:54:11 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 22:14:25 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;

	cdst = (char *)dst;
	csrc = (const char *)src;
	if (cdst < csrc)
	{
		while (0 < len)
		{
			*cdst++ = *csrc++;
			len--;
		}
	}
	else if (csrc < cdst)
	{
		cdst += len - 1;
		csrc += len - 1;
		while (0 < len)
		{
			*cdst-- = *csrc--;
			len--;
		}
	}
	return (dst);
}
