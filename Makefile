# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agilles <agilles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 16:34:53 by agilles           #+#    #+#              #
#    Updated: 2024/02/20 16:06:11 by agilles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = pipex
NAME = printf_libft.a
LIBFT = printf_libft/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC =	pipex.c\
		#utils.c\


MAIN = pipex.c\

OBJ = $(SRC:.c=.o)

all : $(EXEC)

clean :
	rm -f $(OBJ)
	$(MAKE) clean -C $$(dirname $(LIBFT))

fclean : clean
	rm -f $(NAME)
	rm -f $(EXEC)
	$(MAKE) fclean -C $$(dirname $(LIBFT))

re : fclean all

$(LIBFT) :
	$(MAKE) -C $$(dirname $@)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(EXEC) : $(NAME)
	$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $@

