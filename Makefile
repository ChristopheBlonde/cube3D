# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblonde <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 09:14:44 by cblonde           #+#    #+#              #
#    Updated: 2024/09/18 13:33:39 by cblonde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Werror -Wextra -Wall -g

INCLUDE = -Iinclude -Ilib -Imlx

LIBRARIES = -Llib -lft -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

DSRC = src/

DMAP = src/map/

DPARSE = src/parse/

DPLAYER = src/player/

DLIB = lib/

DERR = src/error/

LIB = $(DLIB)libft.a

DMLX = mlx/

MLX = $(DMLX)libmlx.a

SRC = $(DSRC)main.c $(DMAP)utils_map.c $(DPARSE)ft_readfile.c\
	  $(DPARSE)initialize_map.c $(DERR)err_ptr.c $(DPARSE)get_map_infos.c\
	  $(DERR)err_file.c $(DPARSE)get_map_colors.c $(DPLAYER)util_player.c\
	  $(DPARSE)handle_map_err.c $(DPARSE)util_map_err.c $(DERR)err_map.c\
	  $(DERR)validated.c

NAME = cube

all : $(NAME)

DBUILD = build/

OBJ = $(addprefix $(DBUILD),$(SRC:%.c=%.o))

$(DBUILD)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(LIB) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBRARIES) -o $(NAME)

$(LIB) :
	@make -C $(DLIB) --no-print-directory --silent

$(MLX) :
	@make -C $(DMLX) --no-print-directory --silent

clean :
	@make clean -C $(DLIB) --no-print-directory --silent
	@make clean -C $(DMLX) --no-print-directory --silent
	@rm -rf $(DBUILD)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(LIB)

re : fclean $(NAME)

.PHONY: all clean fclean re
