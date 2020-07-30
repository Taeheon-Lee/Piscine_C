# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 11:28:48 by tlee              #+#    #+#              #
#    Updated: 2019/10/30 23:13:19 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Wextra -Werror -c ft_putchar.c
gcc -Wall -Wextra -Werror -c ft_putstr.c
gcc -Wall -Wextra -Werror -c ft_strcmp.c
gcc -Wall -Wextra -Werror -c ft_strlen.c
gcc -Wall -Wextra -Werror -c ft_swap.c
ar rc libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
ranlib libft.a
