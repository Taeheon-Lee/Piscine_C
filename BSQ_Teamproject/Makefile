# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunkim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 13:16:43 by sunkim            #+#    #+#              #
#    Updated: 2019/11/13 21:10:47 by sunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAG = -Wall -Wextra -Werror
SRC = bsq.c check_error.c list.c main.c

all: $(NAME)

$(NAME):
	gcc $(FLAG) -o $(NAME) $(SRC)

clean:
	/bin/rm -f $(NAME)

re: clean all
