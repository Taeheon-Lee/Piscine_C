/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:34:07 by tlee              #+#    #+#             */
/*   Updated: 2019/10/29 23:49:06 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;
	int length;

	length = 0;
	i = 0;
	while (str[length] != 0)
		length++;
	while (i < length)
	{
		ft_putchar(str[i]);
		i++;
	}
}
