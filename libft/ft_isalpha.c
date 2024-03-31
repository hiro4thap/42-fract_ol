/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:31:17 by hiono             #+#    #+#             */
/*   Updated: 2024/03/08 12:24:22 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <ctype.h>
void test(char c)
{
	printf("%c | %d %d\n", c, ft_isalpha(c), isalpha(c));
}

int	main(void)
{
	test('a' - 1);
	test('a');
	test('z');
	test('z' + 1);
	test('A' - 1);
	test('A');
	test('Z');
	test('Z' + 1);
}
*/