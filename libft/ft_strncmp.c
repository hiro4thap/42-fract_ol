/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:47:09 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 23:07:37 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)(s1) - *(unsigned char *)(s2));
		s1++;
		s2++;
		++i;
	}
	if (i != n)
		return (*(unsigned char *)(s1) - *(unsigned char *)(s2));
	return (0);
}
