/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 03:33:08 by tlee              #+#    #+#             */
/*   Updated: 2019/10/29 13:40:40 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i != n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i >= n)
		dest[n + 1] = 0;
	else
		while (i != n + 1)
			dest[i++] = 0;
	return (dest);
}
