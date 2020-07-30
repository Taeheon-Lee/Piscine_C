/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:27:26 by tlee              #+#    #+#             */
/*   Updated: 2019/11/03 22:27:57 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	change(char **f);
int		sudoku(char **f, int i);
int		check_frame(char **f, int input);

int		main(int argc, char **argv)
{
	if (check_frame(argv, argc))
	{
		if (sudoku(argv, 0) == 1)
			change(argv);
		else
		{
			ft_putstr("Error");
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putstr("Error");
		ft_putchar('\n');
	}
	return (0);
}
