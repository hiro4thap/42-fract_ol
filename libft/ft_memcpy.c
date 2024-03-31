/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:31:02 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 21:36:29 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/*
void test(unsigned int n)
{
	const char src[] = "ab\0de";
	char dst1[] = "1234567890";
	char dst2[] = "1234567890";
	ft_memcpy(dst1, src, n);
	memcpy(dst2, src, n);
	write(1, dst1, 10);
	write(1, " ", 1);
	write(1, dst2, 10);
	write(1, "\n", 1);
}

int main(void)
{
	test(0);
	test(4);
}
*/
