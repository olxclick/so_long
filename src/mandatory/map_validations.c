/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:28:07 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 13:24:39 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_first(t_root *root, size_t x, size_t y)
{
	while (x < root->map.last_x)
	{
		if (root->map.map[0][x] != WALL)
		{
			while (y < root->map.last_y)
			{
				free(root->map.map[y]);
				y++;
			}
			free(root->map.map);
			return (0);
		}
		x++;
	}
	return (1);
}

int	check_second(t_root *root, size_t x, size_t y)
{
	while (y < root->map.last_y)
	{
		if (root->map.map[y][0] != WALL)
		{
			while (x <= root->map.last_x)
			{
				free(root->map.map[x]);
				x++;
			}
			free(root->map.map);
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_third(t_root *root, size_t x, size_t y)
{
	while (x < root->map.last_x)
	{
		if (root->map.map[root->map.last_y - 1][x] != WALL)
		{
			while (y < root->map.last_y)
			{
				free(root->map.map[y]);
				y++;
			}
			free(root->map.map);
			return (0);
		}
		x++;
	}
	return (1);
}

int	check_fourth(t_root *root, size_t x, size_t y)
{
	while (y < root->map.last_y)
	{
		if (root->map.map[y][root->map.last_x - 1] != WALL)
		{
			while (x <= root->map.last_x)
			{
				free(root->map.map[x]);
				x++;
			}
			free(root->map.map);
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_rectangular(t_root *root)
{
	size_t	y;

	y = -1;
	while (++y < root->map.last_y)
		if (ft_strlen(root->map.map[y]) - 1 != root->map.last_x)
			return (0);
	return (1);
}
