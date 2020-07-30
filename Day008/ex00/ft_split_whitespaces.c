/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 01:10:32 by tlee              #+#    #+#             */
/*   Updated: 2019/11/01 15:36:35 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		count_words(char *str)
{
	int words;
	int i;

	i = 0;
	words = 1;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			words++;
			i++;
		}
		i++;
	}
	return(words);
}

int		*count_char_words(char *str)
{
	int i;
	int j;
	int words;
	int *count;

	i = 0;
	j = 1;
	words = count_words(str);
	count = (int *)malloc(sizeof(int) * (words + 1));
	count[0] = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			count[j] = i - count[j - 1];
			j++;
			i++;
		}
		i++;
	}
	count[j] = i - 1;
	return (count);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	int		words;
	int		*num;
	char	**sp;

	i = 1;
	k = 0;
	j = 0;
	if (str[0] == 0)
		return (0);
	else
	{
		words = count_words(str);
		num = count_char_words(str);
		sp = (char**)malloc(sizeof(char*) * (words + 1));
		while (str[i])
		{
			sp[j] = (char*)malloc(sizeof(char) * num[i]);
			while (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
				{
					sp[j][k] = str[i];
					i++;
					k++;
				}
			i++;
			j++;
			k = 0;
		}
	}
	return (sp);
}
	
int main(void)
{
	char	*test = "taeheon is my name";
	char	**out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out = ft_split_whitespaces(test);
	while (out[j][i])
	{
		while (out[j][i])
		{
			printf("%c", out[j][i]);
			i++;
		}
		printf("%c", '\n');
		i = 0;
		j++;
	}
	return (0);
}
