/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:46:52 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 13:57:54 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen((char *)src);
	new = (char *)malloc(size * sizeof(char) + 1);
	if (new != 0)
	{
		while (src[i] != '\0')
		{
			new[i] = src[i];
			i++;
		}
	}
	else
	{
		return (0);
	}
	new[i] = '\0';
	return (new);
}

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

int	count_zeros(t_root *root)
{
	size_t	i;
	size_t	j;
	int		num_zeros;

	num_zeros = 0;
	i = 0;
	while (i < root->map.last_y)
	{
		j = 0;
		while (j < root->map.last_x)
		{
			if (root->map.map[i][j] == '0')
				num_zeros++;
			j++;
		}
		i++;
	}
	return (num_zeros);
}
