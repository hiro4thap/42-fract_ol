/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:57:15 by hiono             #+#    #+#             */
/*   Updated: 2024/03/12 14:09:01 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(char sp, va_list args)
{
	int	i;

	i = 0;
	if (sp == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (sp == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (sp == 'p')
		i = ft_putadr(va_arg(args, unsigned long));
	else if (sp == 'd' || sp == 'i')
		i = ft_putint(va_arg(args, int));
	else if (sp == 'u')
		i = ft_putuint(va_arg(args, unsigned int));
	else if (sp == 'x')
		i = ft_puthxl(va_arg(args, int));
	else if (sp == 'X')
		i = ft_puthxu(va_arg(args, int));
	else if (sp == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				i += ft_specifier(*format, args);
			else
			{
				i += ft_putchar('%');
				break ;
			}
		}
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}
