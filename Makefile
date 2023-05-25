# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 16:15:14 by jbranco-          #+#    #+#              #
#    Updated: 2023/04/20 15:35:40 by jbranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c src/mandatory/utils2.c src/mandatory/utils.c src/mandatory/map_utils.c src/mandatory/player_moves.c src/mandatory/map_validations.c src/mandatory/mlx_control.c src/mandatory/game_start.c src/mandatory/map_creation.c src/mandatory/flood_fill.c
SRC_BONUS = main.c src/so_long_bonus/utils_bonus.c src/so_long_bonus/utils.c src/so_long_bonus/map_utils.c src/so_long_bonus/flood_fill.c src/so_long_bonus/player_moves_bonus.c src/so_long_bonus/map_validations_bonus.c src/so_long_bonus/mlx_control_bonus.c src/so_long_bonus/game_start_bonus.c src/so_long_bonus/map_creation_bonus.c
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS =  -Wall -Wextra -Werror -fsanitize=address -fPIE
FT_PRINTF_A = ./ft_printf/libftprintf.a
GET_NEXT_LINE = ./get_next_line/get_next_line.a

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_A) $(GET_NEXT_LINE)
	cc $(CFLAGS) $(OBJS) -L. ./get_next_line/get_next_line.a ./ft_printf/libftprintf.a -L ./mlx -lmlx -Ilmlx -lXext -lX11 -o $(NAME)

bonus: $(OBJS_BONUS) $(FT_PRINTF_A) $(GET_NEXT_LINE)
	cc $(CFLAGS) $(OBJS_BONUS) -L. ./get_next_line/get_next_line.a ./ft_printf/libftprintf.a -L ./mlx -lmlx -Ilmlx -lXext -lX11 -o $(NAME)

$(FT_PRINTF_A):
	make -C ft_printf

$(GET_NEXT_LINE):
	make -C get_next_line

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	make clean -C ft_printf
	make clean -C get_next_line

fclean: clean
	rm -rf $(NAME) $(FT_PRINTF_A) $(GET_NEXT_LINE)
	
re: clean all
