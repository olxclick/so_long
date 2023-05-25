# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbranco- <jbranco-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:51:17 by jbranco-          #+#    #+#              #
#    Updated: 2023/04/20 15:36:06 by jbranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAND = ft_printf.c ft_printf_utils.c putn.c val_size.c
#BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c\
                ft_lstnew.c ft_lstsize.c

OBJ_MAND = $(MAND:.c=.o)
#OBJ_BONUS = $(BONUS:.c=.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror -fPIE

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ_MAND)
	ar rc $(NAME) $(OBJ_MAND)

#bonus: $(OBJ_MAND) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS) $(OBJ_MAND)

clean:
	rm -rf $(OBJ_MAND)

fclean: clean
	rm -f $(NAME)

re : fclean all
