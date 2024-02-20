# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agilles <agilles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 16:14:24 by agilles           #+#    #+#              #
#    Updated: 2024/01/16 15:25:25 by agilles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_printf.out
NAME = libftprintf.a
LIB = libft/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC =	ft_printf.c\
		ft_put_s.c\
		ft_putchar.c\
		ft_put_di.c\
		ft_put_u.c\
		ft_put_p.c\
		ft_put_x.c\
#		main.c\

#MAIN = main.c

OBJ = $(SRC:.c=.o)

#comp : $(EXEC)
#	mv a.out $(EXEC)

all : $(NAME)

clean :
	rm -f $(OBJ)
	rm -f $(LIB)
	rm -f libft/*.o

fclean : clean
	rm -f $(NAME)
#	rm -f $(EXEC)

re : fclean all

$(LIB) :
	$(MAKE) -C $$(dirname $@)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

#$(EXEC) : $(NAME)
#	$(CC) $(CFLAGS) $(MAIN) $(NAME)


