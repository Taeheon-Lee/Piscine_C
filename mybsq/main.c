/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:42:05 by tlee              #+#    #+#             */
/*   Updated: 2019/11/13 17:25:46 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int		check_error(int fd, char *buf, int i, char *argv);

int		*line_count(int fd, char *buf, int i)
{
	int		row;
	int		column;
	int		*count;

	row = 0;
	column = 0;
	count = (int*)malloc(sizeof(int) * 2);
	while (i)
	{
		row = 0;
		while (buf[0] != '\n')
		{
			i = read(fd, buf, 1);
			column++;
		}
		buf[0] = ' ';
		row++;
	}
	count[0] = row;
	count[1] = column;
	return (count);
}

char	**input_frame(int fd, char *buf)
{
	int		i;
	int		j;
	int		*count;
	char	**input;

	i = -1;
	j = -1;
	count = line_count(fd, buf, 1);
	input = (char**)malloc(sizeof(char*) * (count[0] + 1));
	while (++i < count[0] - 1)
	{
		input[i] = (char*)malloc(sizeof(char) * (count[1] + 1));
		while (++j <= count[1])
			input[i][j] = '\0';
		j = -1;
	}
	return (input);
}

char	**input(int fd, char *buf, int i, char **frame)
{
	int j;
	int k;

	k = 0;
	frame = input_frame(fd, buf);
	while (1)
	{
		j = 0;
		while (buf[0] != '\n')
		{
			i = read(fd, buf, 1);
			if (i == 0)
				break ;
			buf[i] = '\0';
			frame[k][j] = buf[0];
			j++;
		}
		if (i == 0)
			break ;
		frame[k][j] = buf[0];
		buf[0] = ' ';
		k++;
	}
	return (frame);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	buf[2];
	char	**frame;

	i = 0;
	if (argc < 2)
		fd = 0;
	else
	{
		while (argv[++i])
		{
			fd = open(argv[i], O_RDWR);
			if (fd == -1 || check_error(fd, buf, 1, argv[i]) == -1)
			{
				write(1, "map error", 9);
				return (1);
			}
			frame = input(fd, buf, 1, frame);
			bsq(frame, 0);
			free(frame);
		}
	}
	return (0);
}
