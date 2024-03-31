/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:23:11 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 22:26:42 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_strcat(char *dst, const char *src)
{
	int		i;
	int		len;

	len = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	ls1;
	size_t	ls2;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '\0';
	ft_strcat(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}
