/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:41:45 by jbranco-          #+#    #+#             */
/*   Updated: 2022/12/10 14:46:11 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	val_size_dec(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	val_size_u(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		return (10);
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	val_size_hex(size_t n)
{
	int	size;

	size = 1;
	while (n > 15)
	{
		n /= 16;
		size++;
	}
	return (size);
}
