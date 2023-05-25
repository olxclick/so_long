/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:30:00 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 13:50:13 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	find_char(t_root *root)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < root->map.last_y)
	{
		j = -1;
		while (++j < root->map.last_x)
			if (!verify_pos_counter(root, i, j))
				return (0);
	}
	if (root->map.n_exits != 1 || root->map.n_players != 1 \
	|| root->counter.collectibles < 1)
		return (0);
	return (1);
}

void	save_map(char *str, t_root *root)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return ;
	root->map.map = malloc(1 * sizeof(char *));
	while (line)
	{
		root->map.map[i] = line;
		i++;
		root->map.map = ft_realloc_map(root->map.map, i + 1);
		line = get_next_line(fd);
	}
	close(fd);
	root->map.map[i] = NULL;
}

void	add_enemy(t_root *root)
{
	int	row;
	int	col;
	int	en;

	en = count_zeros(root) / DENSITY;
	while (en-- > 1)
	{
		row = rand() % root->map.last_y;
		col = rand() % root->map.last_x;
		if (root->map.map[row][col] == '0')
			root->map.map[row][col] = 'A';
	}
}

int	map_verify(t_root *root)
{
	int	success;

	success = 0;
	if (!root || !root->map.map)
		return (0);
	if (!check_walls(root) || !check_chars(root))
		return (0);
	add_enemy(root);
	create_flood_fill_map(root);
	success = flood_fill(root, root->player.y / SIZE, root->player.x / SIZE);
	if (!success && root->map.enemy_found)
		retry_enemy(root, success);
	else if (!success)
		return (0);
	return (1);
}

int	check_walls(t_root *root)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	root->map.last_y = ncolumns(root->map.map);
	root->map.last_x = ft_strlen(root->map.map[0]) - 1;
	if (!check_rectangular(root))
		return (0);
	if (!check_first(root, x, y) || !check_second(root, x, y) \
		|| !check_third(root, x, y) || !check_fourth(root, x, y))
		return (0);
	return (1);
}
