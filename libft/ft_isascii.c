/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:58:50 by hiono             #+#    #+#             */
/*   Updated: 2024/03/08 12:24:29 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

/*
#include <ctype.h>
void test(char c)
{
	printf("%c | %d, %d\n", c, ft_isascii(c), isascii(c));
}

int	main(void)
{
	test(0);
	test(127);
	test(0b10000000);
}
*/