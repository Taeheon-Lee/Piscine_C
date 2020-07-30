/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:42:37 by tlee              #+#    #+#             */
/*   Updated: 2019/10/26 00:42:41 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int c;
	int d;
	int *add3;
	int *add4;
	
	c = *a / *b;
	d = *a % *b;
	add3 = &c;
	add4 = &d;
	write(1, &add3, 1);
	write(1, &add4, 1);
}

int		main(void)
{
	int A;
	int B;
	int *add1;
	int *add2;

	A = 10;
	B = 20;
	add1 = &A;
	add2 = &B;
	ft_ultimate_div_mod(add1, add2);
	return(0);
}
