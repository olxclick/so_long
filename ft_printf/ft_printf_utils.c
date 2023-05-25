/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:03:30 by jbranco-          #+#    #+#             */
/*   Updated: 2022/12/10 14:49:38 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//all of the printing functions

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

size_t	ft_putpointer_hex(size_t n)
{
	int	size;

	if (n == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	size = 0;
	ft_putstr("0x");
	size = ft_puthex_lower(n);
	return (size + 2);
}

int	ft_puthex_lower(size_t n)
{
	int	size;

	size = val_size_hex(n);
	if (n > 15)
	{
		ft_puthex_lower(n / 16);
		ft_puthex_lower(n % 16);
	}
	else
		ft_putchar("0123456789abcdef"[n]);
	return (size);
}

int	ft_puthex_upper(size_t n)
{
	int	size;

	size = val_size_hex(n);
	if (n > 15)
	{
		ft_puthex_upper(n / 16);
		ft_puthex_upper(n % 16);
	}
	else
		ft_putchar("0123456789ABCDEF"[n]);
	return (size);
}
