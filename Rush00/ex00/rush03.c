/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:39:28 by tlee              #+#    #+#             */
/*   Updated: 2019/10/27 22:25:51 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_last(int i, int x)
{
	while (i <= x)
	{
		if (i == 1)
			ft_putchar('A');
		else if (i == x)
			ft_putchar('C');
		else
			ft_putchar('B');
		i++;
	}
	ft_putchar('\n');
}

void	middle(int i, int x)
{
	while (i <= x)
	{
		if (i == 1 || i == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int a;
	int i;

	if (x > 0 && y > 0)
	{
		a = 1;
		while (a <= y)
		{
			i = 1;
			if (a == 1 || a == y)
			{
				first_last(i, x);
			}
			else
			{
				middle(i, x);
			}
			a++;
		}
	}
}
