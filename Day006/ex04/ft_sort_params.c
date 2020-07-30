/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:31:02 by tlee              #+#    #+#             */
/*   Updated: 2019/10/30 23:40:29 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(char *a, char *b)
{
	char	*c;
	
	c = a;
	a = b;
	b = c;
}

void	ft_printsort(int argc, char **argv)
{	
	int i;
	
	i = 1;
	while (i < argc)
	{
		while (*argv[i])
			ft_putchar(*argv[i]++);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		x;
	int		y;
	int		z;

	x = 1;
	while(x != argc - 1)
	{
		y = 0;
		z = 0;
		while (argv[x][y] == 0)
		{
			if (argv[x][y] > argv[z + 1][y])
			{
				ft_swap(argv[x], argv[x + 1]);
				x++;
				continue;
			}
			else if (argv[x][y] != 0)
			{
				z++;
				x = z;
				continue;
			}
			break;
		}
		x++;
	}
	ft_printsort(argc, argv);
	return (0);
}
