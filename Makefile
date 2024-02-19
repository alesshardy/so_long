# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apintus <apintus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 17:16:05 by apintus           #+#    #+#              #
#    Updated: 2024/02/19 15:27:33 by apintus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################################
## ARGUMENTS

NAME = so_long
ARCHIVE = so_long.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g
MAKE_LIB = ar -rcs
MLX = -L mlx -l mlx -I mlx -lXext -lX11 -lm -lz

##########################################################
## SOURCES

SRCS = main.c\
		check_extension.c\
		get_map.c\
		check_map.c\
		exit.c\
		check_flood_fill.c\
		game.c\
		move.c\


OBJS = $(SRCS:.c=.o)

# LIBFT
LIBFT_DIR = libft
LIBFT_MAKE_COMMAND = make -s -C $(LIBFT_DIR)
LIBFT_PATH = $(LIBFT_DIR)/libft.a

##########################################################
## RULES

all : $(NAME) $(LIBFT_PATH)

$(NAME) : $(ARCHIVE) $(LIBFT_PATH)
	make -C mlx
	$(CC) $(ARCHIVE) $(LIBFT_PATH) $(MLX) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH) :
	$(LIBFT_MAKE_COMMAND)

clean :
	$(RM) $(OBJS) $(ARCHIVE)
	$(RM) $(OBJS_BONUS)
	$(LIBFT_MAKE_COMMAND) clean
	make -C mlx clean

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(LIBFT_MAKE_COMMAND) fclean

re : fclean all

.PHONY : all clean fclean re
