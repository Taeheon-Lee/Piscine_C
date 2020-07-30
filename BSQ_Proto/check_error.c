/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:48:40 by sunkim            #+#    #+#             */
/*   Updated: 2019/11/13 23:39:14 by sunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mybsq.h"

int		find_eof(int d, char **argv, int *var)
{
	int		fd;
	char	c;
	t_list	*start;

	start = init_list();
	fd = open(argv[d], O_RDONLY);
	read(fd, &c, 1);
	while (c != '\n')
	{
		list_push(c, start);
		read(fd, &c, 1);
	}
	var[2] = list_pop(start);
	var[1] = list_pop(start);
	var[0] = list_pop(start);
	if (var[2] == '\0' || var[1] == '\0' || var[0] == '\0')
		return (-1);
	if (var[2] == var[1] || var[1] == var[0] || var[0] == var[2])
		return (-1);
	var[3] = bsq_atoi(start);
	if (var[3] < 0)
		return (-1);
	free_all(start);
	close(fd);
	return (var[3]);
}

int		check_line(char c, int *cvvar)
{
	if (c == '\n')
	{
		if (cvvar[2] == 0)
			cvvar[2] = cvvar[1];
		else if (cvvar[2] != cvvar[1] - 1)
			return (-1);
		cvvar[0]++;
		cvvar[1] = 0;
	}
	cvvar[1]++;
	return (0);
}

int		check_valid(int d, char **argv, int *var)
{
	int		cvvar[3];
	char	c;
	int		fd;

	cvvar[0] = 0;
	cvvar[1] = 0;
	cvvar[2] = 0;
	if (d == 0)
		fd = 0;
	else
		fd = open(argv[d], O_RDONLY);
	read(fd, &c, 1);
	while (c != '\n')
		read(fd, &c, 1);
	while (read(fd, &c, 1))
		if (check_line(c, cvvar) < 0)
			return (-1);
	close(fd);
	if (cvvar[0] != var[3] || cvvar[0] == 0)
		return (-1);
	return (cvvar[2]);
}

int		check_map(char c, int **arr, int *var, int *cnt)
{
	if (c == var[0])
	{
		arr[cnt[0]][cnt[1]] = 1;
		cnt[1]++;
	}
	else if (c == var[1])
	{
		arr[cnt[0]][cnt[1]] = 0;
		cnt[1]++;
	}
	else if (c == '\n')
	{
		cnt[1] = 0;
		cnt[0]++;
	}
	else
		return (-1);
	return (0);
}

int		convert(int d, char **argv, int **arr, int *var)
{
	int		fd;
	int		cnt[3];
	char	c;

	cnt[0] = 0;
	cnt[1] = 0;
	if (d == 0)
		fd = 0;
	else
		fd = open(argv[d], O_RDONLY);
	read(fd, &c, 1);
	while (c != '\n')
		read(fd, &c, 1);
	while (read(fd, &c, 1))
		if (check_map(c, arr, var, cnt) == -1)
			return (-1);
	close(fd);
	return (0);
}
