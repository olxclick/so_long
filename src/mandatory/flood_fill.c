/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:57:11 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 15:25:25 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	create_flood_fill_map(t_root *root)
{
	size_t	i;
	size_t	j;

	i = -1;
	root->flood_fill.map = (char **)malloc(root->map.last_y * sizeof(char *));
	while (++i < root->map.last_y)
		root->flood_fill.map[i] = (char *)malloc(\
			root->map.last_x * sizeof(char));
	i = -1;
	while (++i < root->map.last_y)
	{
		j = -1;
		while (++j < root->map.last_x)
			root->flood_fill.map[i][j] = root->map.map[i][j];
	}
}

int	flood_fill(t_root *root, size_t i, size_t j)
{
	if (i > root->map.last_y - 1 || j > root->map.last_x - 1)
		return (0);
	else if (root->flood_fill.map[i][j] == WALL)
		return (0);
	else if (root->flood_fill.map[i][j] == COLLECTIBLE)
		root->counter.flood_col++;
	else if (root->flood_fill.map[i][j] == EXIT)
		root->counter.flood_exits++;
	root->flood_fill.map[i][j] = WALL;
	flood_fill(root, i + 1, j);
	flood_fill(root, i - 1, j);
	flood_fill(root, i, j + 1);
	flood_fill(root, i, j - 1);
	return (root->counter.flood_col == root->counter.collectibles \
	&& root->counter.flood_exits == root->map.n_exits);
}
