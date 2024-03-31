/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:59:20 by hiono             #+#    #+#             */
/*   Updated: 2024/03/08 15:36:01 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	l;

	i = 0;
	l = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (*haystack && i + l < len)
	{
		i = 0;
		while (haystack[i] == needle[i] && i + l < len)
		{
			i++;
			if (needle[i] == '\0')
			{
				return ((char *)haystack);
			}
		}
		haystack++;
		l++;
	}
	return (0);
}
