/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:35:04 by sunkim            #+#    #+#             */
/*   Updated: 2019/11/13 20:56:00 by sunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mybsq.h"

int		execution(int d, char **argv)
{
	int		**arr;
	int		var[6];
	int		i;

	var[3] = find_eof(d, argv, var);
	if (var[3] <= 0)
		return (-1);
	var[4] = check_valid(d, argv, var);
	if (var[4] <= 0)
		return (-1);
	arr = (int**)malloc(sizeof(int*) * var[3]);
	i = 0;
	while (i < var[3])
	{
		arr[i] = (int*)malloc(sizeof(int) * var[4]);
		i++;
	}
	if (convert(d, argv, arr, var) < 0)
		return (-1);
	var[5] = find_square(arr, var);
	print_array(arr, var);
	free(arr);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;
	int ise;

	ise = 0;
	i = 1;
	if (argc == 1)
		ise = execution(0, argv);
	else
		while (i < argc)
		{
			ise = execution(i, argv);
			i++;
		}
	if (ise == -1)
	{
		write(1, "map error\n", 10);
		return (-1);
	}
	return (0);
}
