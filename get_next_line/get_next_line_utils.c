/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:25:49 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/13 16:43:52 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str, const char *str2)
{
	char	*temp;
	int		i;
	int		len1;
	int		len2;

	if (!str || !str2)
		return (NULL);
	len1 = ft_strlen((char *)str);
	len2 = ft_strlen ((char *)str2);
	temp = malloc((len1 + len2 + 1) * sizeof(const char));
	if (!temp)
		return (NULL);
	i = 0;
	while (len1 > i)
		temp[i++] = *str++;
	i = 0;
	while (len2 > i)
		temp[len1 + i++] = *str2++;
	temp[len1 + i] = '\0';
	return (temp);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	if (size != '\0')
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	dest[i] = '\0';
	}
	return (j);
}

char	*ft_strchr(const char *str, int c)
{
	char	search;

	search = c;
	while (*str != search)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
