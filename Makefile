# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/03 15:30:43 by pivanovi          #+#    #+#              #
#    Updated: 2014/04/21 19:45:22 by pivanovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = lemipc

SRC =		tools/strings_to_number.c		\
			tools/print_strings.c			\
			tools/frees.c					\
			src/check_dir_player.c			\
			src/lock_unlock.c				\
			src/check_dir.c					\
			src/moving.c					\
			src/am_i.c						\
			src/main.c						\
			src/map.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I./includes -I /usr/X11/include
LIBX = -L /usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBX)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
