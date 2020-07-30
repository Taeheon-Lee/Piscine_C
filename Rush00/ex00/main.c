/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:11:20 by tlee              #+#    #+#             */
/*   Updated: 2019/10/27 20:05:26 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);

int		main(void)
{
	rush(5, 3);
	ft_putchar('\n');
	rush(5, 1);
	ft_putchar('\n');
	rush(1, 1);
	ft_putchar('\n');
	rush(1, 5);
	ft_putchar('\n');
	rush(4, 4);
	ft_putchar('\n');
	return (0);
}
