/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:32:22 by hiono             #+#    #+#             */
/*   Updated: 2024/03/09 22:27:46 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	while (i < size * count)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}
