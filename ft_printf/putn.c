/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:43:29 by jbranco-          #+#    #+#             */
/*   Updated: 2022/12/10 14:43:41 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	size;

	size = val_size_dec(n);
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr(n);
	}
	else
		ft_putchar(n + '0');
	return (size);
}

size_t	ft_putnbr_u(size_t n)
{
	size_t	size;

	size = val_size_u(n);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (size);
}
