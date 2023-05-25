/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:03:17 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/19 16:46:23 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	destroy(t_root *root)
{
	if (!root)
		exit(0);
	destroy_images(root);
	if (root->vars.win)
		mlx_destroy_window(root->vars.mlx, root->vars.win);
	if (root->vars.mlx)
	{
		mlx_destroy_display(root->vars.mlx);
		free(root->vars.mlx);
	}
	free_map(root);
	if (root->counter.finished == 1)
		ft_printf("Game Over Buddy :)\n");
	exit(0);
}

void	finish_game(t_root *root)
{
	if (root->counter.collectibles == root->player.collected)
	{
		ft_printf("Mission Accomplished!\n");
		root->counter.finished = 1;
		destroy(root);
	}
}

int	key_press_control(int keycode, t_root *root)
{
	if (!keycode)
		return (0);
	else if (keycode == ESC)
		destroy(root);
	process_position(root, keycode);
	return (1);
}

void	destroy_images(t_root *root)
{
	if (root->img.collectible)
		mlx_destroy_image(root->vars.mlx, root->img.collectible);
	if (root->img.enemy)
		mlx_destroy_image(root->vars.mlx, root->img.enemy);
	if (root->img.exit)
		mlx_destroy_image(root->vars.mlx, root->img.exit);
	if (root->img.wall)
		mlx_destroy_image(root->vars.mlx, root->img.wall);
	if (root->img.empty)
		mlx_destroy_image(root->vars.mlx, root->img.empty);
	if (root->img.player)
		mlx_destroy_image(root->vars.mlx, root->img.player);
	if (root->img.player2)
		mlx_destroy_image(root->vars.mlx, root->img.player2);
}
