# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 17:51:45 by tlee              #+#    #+#              #
#    Updated: 2019/11/07 18:11:02 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = ft_display_file.c

Object = ft_display_file.o

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
		gcc -Wall -Wextra -Werror -c $(SRC)

clean:
		/bin/rm -f $(Object)

fclean: clean
		/bin/rm -f $(NAME)
