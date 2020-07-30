/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:15:18 by tlee              #+#    #+#             */
/*   Updated: 2019/10/31 23:41:07 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*num;
	int start;
	int i;

	i = 0;
	start = min;
	if (max > min)
	{
		num = (int*)malloc(sizeof(int) * (max - min));
		while (i <= (max - min - 1))
		{
			range[0][i] = start;
			start++;
			i++;
		}
		return(max - min);
	}
	return(0);
}
