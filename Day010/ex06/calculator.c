/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:48:07 by tlee              #+#    #+#             */
/*   Updated: 2019/11/05 23:15:03 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		check(char *val)
{
	int		i;
	int		j;
	int		sign;

	i = 0;
	j = 0;
	sign = 1;
	if (val[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (val[i] != 0)
	{
		if (val[i] >= '0' && val[i] <= '9')
		{
			j = j * 10 + (val[i] - 48);
			i++;
		}
		else
			break ;
	}
	j = j * sign;
	return (j);
}

void	print_num(int num)
{
	int		i;
	char	a;
	char	rev[100];

	i = 0;
	if (num == 0)
		write(1, "0", 1);
	else
	{
		if (num < 0)
		{
			num = num * -1;
			write(1, "-", 1);
		}
		while (num)
		{
			a = (num % 10) + 48;
			num = num / 10;
			rev[i] = a;
			i++;
		}
		while (i--)
			write(1, &rev[i], 1);
	}
}

void	calculator(char *val1, char *operator, char *val2)
{
	int	i;
	int	j;

	i = check(val1);
	j = check(val2);
	if (operator[0] == '+')
		print_num(i + j);
	else if (operator[0] == '-')
		print_num(i - j);
	else if (operator[0] == '*')
		print_num(i * j);
	else if (operator[0] == '/')
		print_num(i / j);
	else if (operator[0] == '%')
		print_num(i % j);
	else
		print_num(0);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (check(argv[3]) == 0)
		{
			if (argv[2][0] == '/')
				write(1, "Stop : division by zero", 23);
			else if (argv[2][0] == '%')
				write(1, "Stop : modulo by zero", 21);
			else
				calculator(argv[1], argv[2], argv[3]);
		}
		else
			calculator(argv[1], argv[2], argv[3]);
	}
	else
		return (0);
}
