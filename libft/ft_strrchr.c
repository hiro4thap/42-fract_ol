/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:01:26 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 21:12:08 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		cc;
	const char	*str;
	int			l;

	cc = (char)c;
	l = ft_strlen(s);
	str = s + l;
	while (l >= 0)
	{
		if (*str == cc)
			return ((char *)str);
		str--;
		l--;
	}
	return (0);
}
