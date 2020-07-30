/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:16:43 by tlee              #+#    #+#             */
/*   Updated: 2019/11/13 17:25:42 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int	check_error_box(int fd, char *buf, int count)
{
	int i;

	i = 1;
	while (1)
	{
		i = read(fd, buf, 1);
		if (buf[0] == '\n')
			break ;
		count++;
		if (i == 0)
			return (-1);
	}
	if (count != check_error_box(fd, buf, 0))
		return (-1);
	return (1);
}

int	check_line(int fd, char *buf, int j, char *arr)
{
	int i;
	int count;
	int	line_index;

	i = 0;
	count = 1;
	line_index = 0;
	while (i)
	{
		i = read(fd, buf, 1);
		if (buf[0] == '\n')
			count++;
	}
	while (i < j - 3)
	{
		line_index = (line_index * 10) + (arr[i] - '0');
		i++;
	}
	if (line_index != count)
		return (-1);
	return (1);
}

int	check_index(int fd, char *buf, int j, char *argv)
{
	char	*arr;
	int		i;

	i = -1;
	close(fd);
	fd = open(argv, O_RDWR);
	arr = (char*)malloc(sizeof(char) * (j + 1));
	while (++i < j + 1)
	{
		read(fd, buf, 1);
		arr[i] = buf[0];
	}
	i = -1;
	if (arr[j - 1] != arr[j - 2] != arr[j - 3])
	{
		while (++i < j - 3)
			if (arr[i] < '0' || arr[i] > '9')
				if (check_line(fd, buf, j, arr) == -1)
					return (-1);
	}
	else
		return (-1);
	return (1);
}

int	check_error(int fd, char *buf, int i, char *argv)
{
	int		first_count;

	first_count = 0;
	fd = open(argv, O_RDWR);
	while (1)
	{
		i = read(fd, buf, 1);
		if (buf[0] == '\n')
		{
			if (first_count < 4)
				return (-1);
			if (check_index(fd, buf, first_count, argv) == 1)
				break ;
		}
		else
			return (-1);
		first_count++;
		if (i == 0)
			return (-1);
	}
	if (check_error_box(fd, buf, 0) == -1)
		return (-1);
	return (1);
}
