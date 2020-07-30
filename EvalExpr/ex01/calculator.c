/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 22:03:04 by tlee              #+#    #+#             */
/*   Updated: 2019/11/10 22:09:52 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	addiction(char a, char b)
{
	int result;

	result = (a - 48) + (b - 48);
	return (result);
}

int	subtration(char a, char b)
{
	int result;

	result = (a - 48) - (b - 48);
	return (result);
}

int	multiplication(char a, char b)
{
	int result;

	result = (a - 48) * (b - 48);
	return (result);
}

int	division(char a, char b)
{
	int result;

	result = (a - 48) / (b - 48);
	return (result);
}

char	modulo(char a, char b)
{
	int result;

	result = (a - 48) % (b - 48);
	return (result);
}
