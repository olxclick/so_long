/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:27:59 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 14:04:53 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little && len == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (!little[++j] && big[i + j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	size_t		i;
	size_t		size;
	char		*new;

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

int	check_extension(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (argv[0] == '.')
		return (0);
	if (!ft_strnstr(argv, ".ber", len))
		return (0);
	return (1);
}
