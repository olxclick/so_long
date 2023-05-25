/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:31:30 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/19 16:14:40 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_put_image_to_window(t_root *root, int column, int line)
{
	if (root->map.map[root->counter.i][root->counter.j] == WALL)
		mlx_put_image_to_window(root->vars.mlx, root->vars.win, root->img.wall,
			column, line);
	else if (root->map.map[root->counter.i][root->counter.j] == EMPTY)
		mlx_put_image_to_window(root->vars.mlx, root->vars.win, root->img.empty,
			column, line);
	else if (root->map.map[root->counter.i][root->counter.j] == COLLECTIBLE)
		mlx_put_image_to_window(root->vars.mlx, root->vars.win,
			root->img.collectible, column, line);
	else if (root->map.map[root->counter.i][root->counter.j] == PLAYER)
		mlx_put_image_to_window(root->vars.mlx, root->vars.win,
			root->img.player, column, line);
	else if (root->map.map[root->counter.i][root->counter.j] == EXIT)
		mlx_put_image_to_window(root->vars.mlx, root->vars.win, root->img.exit,
			column, line);
	else if (root->map.map[root->counter.i][root->counter.j] == ENEMY)
		mlx_put_image_to_window(root->vars.mlx, root->vars.win, root->img.enemy,
			column, line);
	else if (root->map.map[root->counter.i][root->counter.j] != '\n')
		return (on_error(root, "Error! Invalid Chars in Map\n"));
	return (1);
}

t_img	ft_initialize_imgs(t_root *root)
{
	t_img	img;
	int		h;
	int		w;

	img.wall = mlx_xpm_file_to_image(root->vars.mlx, "./textures/wall.xpm", &w,
			&h);
	img.empty = mlx_xpm_file_to_image(root->vars.mlx, "./textures/empty.xpm",
			&w, &h);
	img.collectible = mlx_xpm_file_to_image(root->vars.mlx,
			"./textures/margot.xpm", &w, &h);
	img.exit = mlx_xpm_file_to_image(root->vars.mlx, "./textures/exit.xpm", &w,
			&h);
	img.player = mlx_xpm_file_to_image(root->vars.mlx,
			"./textures/deadpool.xpm", &w, &h);
	img.player2 = mlx_xpm_file_to_image(root->vars.mlx,
			"./textures/deadpool2.xpm", &w, &h);
	img.enemy = mlx_xpm_file_to_image(root->vars.mlx, "./textures/enemy.xpm",
			&w, &h);
	return (img);
}

int	render_image(t_root *root)
{
	int	column;
	int	line;

	line = 0;
	root->counter.i = 0;
	while (root->map.map[root->counter.i])
	{
		root->counter.j = 0;
		column = 0;
		while (root->map.map[root->counter.i][root->counter.j])
		{
			ft_put_image_to_window(root, column, line);
			root->counter.j++;
			column += SIZE;
		}
		line += SIZE;
		root->counter.i++;
	}
	print_movements(root);
	return (1);
}

void	game_start(t_root *root)
{	
	root->vars.mlx = mlx_init();
	root->vars.win = mlx_new_window(root->vars.mlx, root->map.last_x * SIZE,
			root->map.last_y * SIZE, "Rainbow Mafia");
	root->img = ft_initialize_imgs(root);
	render_image(root);
	mlx_hook(root->vars.win, 17, (1L << 17), &destroy, root);
	mlx_hook(root->vars.win, 2, (1L << 0), &key_press_control, root);
	mlx_hook(root->vars.win, 2, (1L << 0), &key_press_control, root);
	mlx_loop(root->vars.mlx);
}
