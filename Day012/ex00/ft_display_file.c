/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:09:38 by tlee              #+#    #+#             */
/*   Updated: 2019/11/07 18:42:02 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	run(int fd, char *buf, int i)
{
	while (i)
	{
		i = read(fd, buf, 1);
		buf[i] = '\0';
		write(1, buf, i);
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	buf[2];

	i = 1;
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		write(1, "open() failed\n", 15);
		return (1);
	}
	run(fd, buf, 1);
	fd = close(fd);
	return (0);
}
