/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:50:15 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 14:05:35 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		len;

	len = get_len(nbr);
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

int	ncolumns(char **map)
{
	int	last_y;

	last_y = 0;
	while (map[last_y])
		last_y++;
	return (last_y);
}
