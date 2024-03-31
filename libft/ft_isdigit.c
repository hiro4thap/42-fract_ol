/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:52:01 by hiono             #+#    #+#             */
/*   Updated: 2024/03/08 12:23:24 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

/*
#include <ctype.h>
void test(char c)
{
	printf("%c | %d, %d\n", c, ft_isdigit(c), isdigit(c));
}

int	main(void)
{
	test('0' - 1);
	test('0');
	test('9');
	test('9' + 1);
	test('a');
	test('Z');
}
*/