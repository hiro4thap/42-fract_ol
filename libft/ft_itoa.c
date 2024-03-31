/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:41:58 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 22:34:14 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static void	ft_insert(char *ptr, int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		*ptr = nb % 10 + '0';
		nb = nb / 10;
		ptr++;
	}
	if (n < 0)
	{
		*ptr = '-';
		ptr++;
	}
	*ptr = '\0';
}

static void	ft_rev(char*tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = *(tab + i);
		*(tab + i) = *(tab + size - i - 1);
		*(tab + size - i - 1) = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	int		l;
	char	*ptr;

	if (n == 0)
	{
		ptr = malloc (2);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	l = ft_getlen(n);
	ptr = malloc(sizeof(char) * (l + 1));
	if (ptr == NULL)
		return (NULL);
	ft_insert(ptr, n);
	ft_rev(ptr, l);
	return (ptr);
}

/*
void test(int n)
{
	printf("%d | %s\n", n, ft_itoa(n));
}

int	main(void)
{
	test(100);
	test(23);
	test(0);
	test(-123);
	test(2147483647);
	test(-2147483648);
}
*/
