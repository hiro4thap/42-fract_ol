/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:57:51 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 21:13:23 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*emp_str(void)
{
	char	*ptr;

	ptr = malloc(sizeof(char));
	*ptr = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	actlen;

	if (ft_strlen(s) < start)
		return (emp_str());
	actlen = 0;
	while (actlen < len && s[start + actlen])
		actlen++;
	ptr = malloc(sizeof(char) * (actlen + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < actlen)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
