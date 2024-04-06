/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:06:50 by hiono             #+#    #+#             */
/*   Updated: 2024/04/06 15:22:11 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putadr(unsigned long ul);
int	ft_putchar(char c);
int	ft_puthxl(unsigned int n);
int	ft_puthxu(unsigned int n);
int	ft_putint(int n);
int	ft_putstr(char *str);
int	ft_putuint(unsigned int n);
int	ft_printf(const char *format, ...);

#endif
