# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 14:11:10 by tlee              #+#    #+#              #
#    Updated: 2019/11/04 19:37:59 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	  ./srcs/ft_strlen.c ./srcs/ft_swap.c

Object = ./ft_putchar.o ./ft_putstr.o ./ft_strcmp.o ./ft_strlen.o ./ft_swap.o

Header = -I ./includes/

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(Header) $(SRC)
	ar rc $(NAME) $(Object)
	ranlib $(NAME)

clean:
	/bin/rm -f $(Object)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
