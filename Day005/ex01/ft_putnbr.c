/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:47:04 by tlee              #+#    #+#             */
/*   Updated: 2019/10/29 22:39:32 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int		i;
	char	number[20];

	i = 0;
	if (nb == -2147483648)
	{
		number[0] = 8;
		nb = nb / 10;
		i = 1;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb == 0)
		ft_putchar('0');
	while (nb != 0)
	{
		number[i++] = nb % 10;
		nb = nb / 10;
	}
	while (i != 0)
		ft_putchar(number[i-- - 1] + '0');
}
