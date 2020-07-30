/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:26:57 by tlee              #+#    #+#             */
/*   Updated: 2019/11/03 22:27:53 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_frame(char **f, int input)
{
	int i;
	int j;

	i = 0;
	if (input == 10)
	{
		while (++i < 10)
		{
			j = 0;
			while (f[i][j])
			{
				if ((f[i][j] < '1' || f[i][j] > '9') && f[i][j] != '.')
					return (0);
				j++;
			}
			if (j != 9)
				return (0);
		}
		return (1);
	}
	else
		return (0);
}

int	check_row(char **f, int row, char nb)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (f[row][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_column(char **f, int column, char nb)
{
	int	i;

	i = 1;
	while (i <= 9)
	{
		if (f[i][column] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_block(char **f, int row, int column, char nb)
{
	int i;
	int j;

	i = -1;
	if (row <= 3)
		row = 1;
	else if (row <= 6)
		row = 4;
	else if (row <= 9)
		row = 7;
	column = column - (column % 3);
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (f[row][column] == nb)
				return (0);
			column++;
		}
		column = column - 3;
		row++;
	}
	return (1);
}
