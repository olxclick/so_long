/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:55:15 by jbranco-          #+#    #+#             */
/*   Updated: 2022/12/10 14:40:42 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.
*/

#include "ft_printf.h"

int	format_process(va_list args, char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		size += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		size += ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == '%')
		size += ft_putchar('%');
	else if (c == 'p')
		size += ft_putpointer_hex(va_arg(args, size_t));
	else if (c == 'x')
		size += ft_puthex_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		size += ft_puthex_upper(va_arg(args, unsigned int));
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			size;

	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			size += format_process(args, format[i]);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}
