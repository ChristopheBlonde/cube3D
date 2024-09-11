# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblonde <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 09:14:44 by cblonde           #+#    #+#              #
#    Updated: 2024/09/11 16:26:37 by cblonde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Werror -Wextra -Wall -g

INCLUDE = -Iinclude -Ilib -Imlx

LIBRARIES = -Llib -lft -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

DSRC = src/

DMAP = src/map/

DPARSE = src/parse/

DLIB = lib/

LIB = $(DLIB)libft.a

DMLX = mlx/

MLX = $(DMLX)libmlx.a

SRC = $(DSRC)main.c $(DMAP)utils_map.c $(DPARSE)ft_readfile.c

NAME = cube

all : $(NAME)

OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(LIB) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBRARIES) -o $(NAME)

$(LIB) :
	make -C $(DLIB) --no-print-directory --silent

$(MLX) :
	make -C $(DMLX) --no-print-directory --silent

clean :
	make clean -C $(DLIB) --no-print-directory --silent
	make clean -C $(DMLX) --no-print-directory --silent
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIB)

re : fclean $(NAME)

.PHONY: all clean fclean re
