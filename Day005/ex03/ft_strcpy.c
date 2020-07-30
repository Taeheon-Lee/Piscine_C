/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:44:59 by tlee              #+#    #+#             */
/*   Updated: 2019/10/29 22:47:19 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int length;
	int i;

	i = 0;
	length = 0;
	while (src[length])
		strength++;
	while (i <= length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i + 1] = 0;
	return (dest);
}
