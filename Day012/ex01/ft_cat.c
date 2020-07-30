/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:22:52 by tlee              #+#    #+#             */
/*   Updated: 2019/11/07 23:41:48 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

char 	*strerror(int errnum);

void	print_error(char *str)
{
	while (*str)
		write(1, &*str, 1);
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	int i;
	int length;

	length = 0;
	i = 0;
	while (str[length] != 0)
		length++;
	while (i < length)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	run(int fd, char *buf, int i)
{
	while (i)
	{
		i = read(fd, buf, 1);
		buf[i] = '\0';
		write(1, buf, i);
	}
}

void	non(void)
{
	char	buff;

	while (read(1, &buff, 1) != '\0')
		write(0, &buff, 1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*filename;
	int		fd;
	char	buf[2];

	i = 1;
	if (argc < 1)
	{
		non();
	}
	while (i < argc)
	{
		filename = argv[i];
		fd = open(filename, O_RDWR);
		if (fd < 0)
		{
			ft_putstr(strerror(errno));
			return (1);
		}
		run(fd, buf, 1);
		close(fd);
		i++;
	}
	return (0);
}
