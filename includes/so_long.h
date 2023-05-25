/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:15:28 by jbranco-          #+#    #+#             */
/*   Updated: 2023/04/20 14:02:34 by jbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define SIZE 64
# define PLAYER 'P'
# define WALL '1'
# define ENEMY 'A'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define EMPTY '0'
# define DENSITY 10
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define MAX_ATTEMPTS 100

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_map
{
	char		**map;
	size_t		last_x;
	size_t		last_y;
	size_t		exit_x;
	size_t		exit_y;
	size_t		n_players;
	size_t		n_exits;
	size_t		enemy_found;
}				t_map;

typedef struct s_img
{
	void		*wall;
	void		*empty;
	void		*collectible;
	void		*enemy;
	void		*player;
	void		*player2;
	void		*exit;
}				t_img;

typedef struct s_player
{
	size_t		x;
	size_t		y;
	size_t		next_x;
	size_t		next_y;
	size_t		collected;
	size_t		flag;
}				t_player;

typedef struct s_counter
{
	size_t		i;
	size_t		j;
	size_t		collectibles;
	size_t		moves;
	size_t		finished;
	size_t		flood_col;
	size_t		flood_exits;
	size_t		flood_enemies;
}				t_counter;

typedef struct s_root
{
	t_vars		vars;
	t_map		map;
	t_map		flood_fill;
	t_player	player;
	t_img		img;
	t_counter	counter;
}				t_root;

int				flood_fill(t_root *root, size_t i, size_t j);
size_t			ft_strlen(char *str);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			save_map(char *str, t_root *root);
char			**ft_realloc_map(char **old_map, size_t new_size);
int				check_extension(char *argv);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_itoa(int n);
int				destroy(t_root *root);
int				key_press_control(int keycode, t_root *root);
void			game_start(t_root *root);
t_img			ft_initialize_imgs(t_root *root);
int				render_image(t_root *root);
void			finish_game(t_root *root);
int				find_char(t_root *root);
int				check_chars(t_root *root);
int				check_player_next(t_root *root);
void			process_position(t_root *root, int keycode);
void			print_movements(t_root *root);
void			free_map(t_root *root);
void			ft_bzero(void *s, size_t n);
void			destroy_images(t_root *root);
void			create_flood_fill_map(t_root *root);
void			add_enemy(t_root *root);
void			clean_enemies(t_root *root);
char			*ft_strdup(const char *src);
int				count_zeros(t_root *root);
int				ncolumns(char **map);
int				retry_enemy(t_root *root, int success);
int				map_verify(t_root *root);
int				check_walls(t_root *root);
int				check_first(t_root *root, size_t x, size_t y);
int				check_second(t_root *root, size_t x, size_t y);
int				check_third(t_root *root, size_t x, size_t y);
int				check_fourth(t_root *root, size_t x, size_t y);
int				verify_pos_counter(t_root *root, int i, int j);
int				check_rectangular(t_root *root);
int				on_error(t_root *root, char *error_msg);

#endif