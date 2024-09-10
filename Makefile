# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblonde <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 09:14:44 by cblonde           #+#    #+#              #
#    Updated: 2024/09/04 10:13:40 by cblonde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Werror -Wextra -Wall -g

INCLUDE = -Iinclude

DSRC = src/

SRC = $(DSRC)main.c

NAME = cube

all : $(NAME)

OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
