/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 03:51:54 by sunkim            #+#    #+#             */
/*   Updated: 2019/11/13 20:54:49 by sunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mybsq.h"
#include <stdio.h>

int		find_minimum(int **arr, int i, int j)
{
	int min;

	if (arr[i][j] == 0)
		return (0);
	min = arr[i][j + 1];
	if (arr[i + 1][j] < min)
		min = arr[i + 1][j];
	if (arr[i + 1][j + 1] < min)
		min = arr[i + 1][j + 1];
	arr[i][j] = min + 1;
	return (min);
}

int		find_square(int **arr, int *var)
{
	int i;
	int j;
	int max[3];
	int min;

	max[0] = 0;
	i = var[3] - 2;
	while (i >= 0)
	{
		j = var[4] - 2;
		while (j >= 0)
		{
			min = find_minimum(arr, i, j);
			if (max[0] <= min)
			{
				max[0] = min;
				max[1] = i * var[4] + j;
			}
			j--;
		}
		i--;
	}
	return (max[1]);
}

void	change_square(int **arr, int *var)
{
	int i;
	int j;
	int param;
	int iend;
	int jend;

	i = var[5] / var[4];
	j = var[5] % var[4];
	param = arr[i][j];
	iend = i + param;
	jend = j + param;
	while (i < iend)
	{
		j = var[5] % var[4];
		while (j < jend)
		{
			arr[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	print_array(int **arr, int *var)
{
	int i;
	int j;

	i = 0;
	change_square(arr, var);
	while (i < var[3])
	{
		j = 0;
		while (j < var[4])
		{
			if (arr[i][j] < 0)
				write(1, &var[2], 1);
			else if (arr[i][j] == 0)
				write(1, &var[1], 1);
			else
				write(1, &var[0], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}
