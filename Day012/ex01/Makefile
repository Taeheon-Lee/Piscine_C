# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 22:40:41 by tlee              #+#    #+#              #
#    Updated: 2019/11/07 22:42:17 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

SRC = ft_cat.c

Object = ft_cat.o

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
		gcc -Wall -Wextra -Werror -c $(SRC)

clean:
		/bin/rm -f $(Object)

fclean: clean
		/bin/rm -f $(NAME)
