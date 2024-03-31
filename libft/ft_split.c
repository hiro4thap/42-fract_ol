/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:30:02 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 23:00:16 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_wrds(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			i++;
		while (*str && *str != c)
			str++;
	}
	return (i);
}

static int	ft_wrdlen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*ft_get_word(const char *src, char c)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_wrdlen(src, c) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i] != c && src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	strs = malloc(sizeof(char *) * (ft_cnt_wrds(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			strs[i] = ft_get_word(s, c);
			s += ft_wrdlen(strs[i], c);
			i++;
		}
		else
			s++;
	}
	strs[i] = 0;
	return (strs);
}
