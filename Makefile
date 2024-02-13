# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apintus <apintus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 17:16:05 by apintus           #+#    #+#              #
#    Updated: 2024/02/13 18:07:47 by apintus          ###   ########.fr        #
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

##########################################################
## SOURCES

SRCS = main.c\
		check_extension.c\
		get_map.c\
		check_map.c\
		exit.c\


OBJS = $(SRCS:.c=.o)

# LIBFT
LIBFT_DIR = libft
LIBFT_MAKE_COMMAND = make -s -C $(LIBFT_DIR)
LIBFT_PATH = $(LIBFT_DIR)/libft.a

##########################################################
## RULES

all : $(NAME) $(LIBFT_PATH)

$(NAME) : $(ARCHIVE) $(LIBFT_PATH)
	$(CC) $(ARCHIVE) $(LIBFT_PATH) -o $(NAME)

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

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(LIBFT_MAKE_COMMAND) fclean

re : fclean all

.PHONY : all clean fclean re
