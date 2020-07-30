/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:28:19 by tlee              #+#    #+#             */
/*   Updated: 2019/10/29 19:33:40 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				out;

	i = 0;
	while (i <= n)
	{
		out = s1[i] - s2[i];
		if (out < 0)
		{
			out = -1;
			break ;
		}
		else if (out > 0)
		{
			out = 1;
			break ;
		}
		i++;
	}
	return (out);
}
