/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:04:35 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 14:05:38 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**ft_realloc_map(char **old_map, size_t new_size)
{
	char	**new_map;
	size_t	i;

	new_map = (char **)malloc(new_size * sizeof(char *));
	if (!new_map)
		return (0);
	i = 0;
	if (new_size > 1)
	{
		while (i < new_size - 1)
		{
			new_map[i] = old_map[i];
			i++;
		}
	}
	new_map[new_size - 1] = NULL;
	free(old_map);
	return (new_map);
}

int	check_chars(t_root *root)
{
	if (find_char(root))
		return (1);
	return (0);
}

void	free_map(t_root *root)
{
	size_t	i;

	if (!root->map.map || !root->flood_fill.map)
		return ;
	i = -1;
	while (++i < root->map.last_y)
		free(root->map.map[i]);
	i = -1;
	while (++i < root->map.last_y)
		free(root->flood_fill.map[i]);
	free(root->flood_fill.map);
	free(root->map.map);
}

int	verify_pos_counter(t_root *root, int i, int j)
{
	if (root->map.map[i][j] == PLAYER)
	{
		root->player.x = j * SIZE;
		root->player.y = i * SIZE;
		root->map.n_players++;
	}
	if (root->map.map[i][j] == EXIT)
	{
		root->map.exit_x = j * SIZE;
		root->map.exit_y = i * SIZE;
		root->map.n_exits++;
	}
	if (root->map.map[i][j] == COLLECTIBLE)
		root->counter.collectibles++;
	return (1);
}

int	count_zeros(t_root *root)
{
	size_t	j;
	size_t	i;
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
