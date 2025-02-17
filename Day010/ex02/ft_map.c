/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:45:48 by tlee              #+#    #+#             */
/*   Updated: 2019/11/05 23:17:08 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *k;

	i = 0;
	k = (int*)malloc(sizeof(int) * length);
	while (i < length)
	{
		k[i] = f(tab[i]);
		i++;
	}
	return (k);
}
