/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:54:00 by tlee              #+#    #+#             */
/*   Updated: 2019/10/31 23:08:49 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min, int max)
{
	int	*num;
	int	start;
	int	i;

	i = 0;
	start = min;
	if (max > min)
	{
		num = (int*)malloc(sizeof(*num) * (max - min));
		while (i <= (max - min - 1))
		{
			num[i] = start;
			start++;
			i++;
		}
		return (num);
	}
	return (0);
}
