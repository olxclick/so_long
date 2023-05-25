/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:50:52 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 14:03:02 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	on_error(t_root *root, char *error_msg)
{
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	destroy(root);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_root	root;

	ft_bzero(&root, sizeof(root));
	save_map(argv[1], &root);
	srand(time(NULL));
	if (argc != 2)
		return (on_error(&root, "Error! Invalid number of arguments.\n"));
	if (!check_extension(argv[1]))
		return (on_error(&root, "Error! Invalid file extension.\n"));
	if (!map_verify(&root))
		return (on_error(&root, \
		"Error! Failed to start the game, check your map.\n"));
	game_start(&root);
	return (0);
}
