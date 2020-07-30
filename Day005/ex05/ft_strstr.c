/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:07:16 by tlee              #+#    #+#             */
/*   Updated: 2019/10/30 00:32:26 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	if (to_find[0] == 0)
		return (str);
	while (*str != 0)
	{
		i = 0;
		while (*str == to_find[i] || to_find[i] == 0)
		{
			if (to_find[i] == 0)
				return (str - i);
			if (*str != to_find[i])
				break ;
			str++;
			i++;
		}
		str = str - i;
		str++;
	}
	return (str);
}
