# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 12:51:32 by cblonde           #+#    #+#              #
#    Updated: 2024/10/11 13:23:46 by cblonde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

INCLUDE = -Idlist -I.

DLST = dlist/

DEPENDENCES = ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			  ft_toupper.c ft_tolower.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c\
			  ft_strlcpy.c ft_strlcat.c ft_memcmp.c ft_memchr.c ft_strchr.c ft_strrchr.c\
			  ft_strncmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_putchar_fd.c\
			  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c\
			  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_printf.c\
			  ft_putlchar.c ft_putlnbr_base.c ft_putlstr.c ft_putlhex.c ft_get_next_line.c\
			  ft_strfjoin.c ft_isspace.c ft_strndup.c ft_lstnew.c ft_lstadd_front.c\
			  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
			  ft_lstiter.c ft_lstmap.c $(DLST)ft_dlstadd_back.c $(DLST)ft_dlstadd_front.c\
			  $(DLST)ft_dlstclear.c $(DLST)ft_dlstdelone.c $(DLST)ft_dlstget.c\
			  $(DLST)ft_dlstget_index.c $(DLST)ft_dlstiter.c $(DLST)ft_dlstlast.c\
			  $(DLST)ft_dlstmap.c $(DLST)ft_dlstnew.c $(DLST)ft_dlstsize.c\
			  ft_strstrim.c ft_arrlen.c ft_free_array.c ft_strtod.c ft_lstget.c\
			  ft_lstiter_param.c ft_foreach.c

OBJDIR = build

OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(DEPENDENCES))

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR) $(OBJDIR)/$(DLST)

clean :
	rm -rf $(OBJDIR)

fclean : clean 
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
