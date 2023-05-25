/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:45:57 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/19 16:44:51 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_player_next(t_root *root)
{
	if (root->map.map[root->player.next_y / SIZE][root->player.next_x
		/ SIZE] == WALL)
		return (0);
	if (root->map.map[root->player.next_y / SIZE][root->player.next_x
		/ SIZE] == COLLECTIBLE)
	{
		root->player.flag = 1;
		root->map.map[root->player.next_y / SIZE][root->player.next_x
			/ SIZE] = EMPTY;
		root->player.collected++;
	}
	if (root->map.map[root->player.next_y / SIZE][root->player.next_x
		/ SIZE] == ENEMY)
	{
		root->counter.finished = 1;
		destroy(root);
	}
	if (root->map.map[root->player.next_y / SIZE][root->player.next_x
		/ SIZE] == EXIT)
		finish_game(root);
	return (1);
}

void	player_check(t_root *root)
{
	if (!check_player_next(root))
		return ;
	mlx_put_image_to_window(root->vars.mlx, root->vars.win, root->img.empty,
		root->player.x, root->player.y);
	mlx_put_image_to_window(root->vars.mlx, root->vars.win, root->img.exit,
		root->map.exit_x, root->map.exit_y);
	if (root->player.flag == 1)
		mlx_put_image_to_window(root->vars.mlx, root->vars.win,
			root->img.player2, root->player.next_x, root->player.next_y);
	else
		mlx_put_image_to_window(root->vars.mlx, root->vars.win,
			root->img.player, root->player.next_x, root->player.next_y);
	root->counter.moves++;
	root->player.x = root->player.next_x;
	root->player.y = root->player.next_y;
	root->player.flag = 0;
	print_movements(root);
}

void	process_position(t_root *root, int keycode)
{
	root->player.next_x = root->player.x;
	root->player.next_y = root->player.y;
	if (keycode == RIGHT)
	{
		root->player.next_x += SIZE;
		player_check(root);
	}
	else if (keycode == LEFT)
	{
		root->player.next_x -= SIZE;
		player_check(root);
	}
	else if (keycode == DOWN)
	{
		root->player.next_y += SIZE;
		player_check(root);
	}
	else if (keycode == UP)
	{
		root->player.next_y -= SIZE;
		player_check(root);
	}
}

void	print_movements(t_root *root)
{
	char	*moves;

	moves = ft_itoa(root->counter.moves);
	mlx_string_put(root->vars.mlx, root->vars.win, root->player.x + 28, \
	root->player.y + 55, 0x0000FF00, moves);
	free(moves);
}
