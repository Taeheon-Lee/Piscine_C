/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdocku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:28:38 by tlee              #+#    #+#             */
/*   Updated: 2019/11/03 22:27:50 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_row(char **f, int row, char nb);
int	check_column(char **f, int column, char nb);
int	check_block(char **f, int row, int column, char nb);

int	sudoku(char **f, int i)
{
	int		row;
	int		column;
	char	nb;

	nb = '0';
	row = (i / 9) + 1;
	column = i % 9;
	if (i == 81)
		return (1);
	if (f[row][column] != '.')
		return (sudoku(f, i + 1));
	while (nb++ < '9')
	{
		if ((check_row(f, row, nb) + check_column(f, column, nb)) == 2)
		{
			if (check_block(f, row, column, nb) == 1)
			{
				f[row][column] = nb;
				if (sudoku(f, i + 1))
					return (1);
			}
		}
	}
	f[row][column] = '.';
	return (0);
}
