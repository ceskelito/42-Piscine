/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:32:21 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/28 23:32:40 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	get_line(char *id, char *buffer)
{
	int		i;
	int		j;
	char	temp[99];

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] >= '0' && (buffer[i] <= '9'))
		{
			temp[j] = buffer[i];
			j++;
		}
		else if (buffer[i] == ':')
		{
			temp[j] = ':';
			if (ft_strcmp(id, temp) == 0)
				return (i + 1);
			j = 0;
		}
		i++;
	}
	return (0);
}

int	print(char *id, char *dir)
{
	int			fd;
	static char	buffer[BUFFER_SIZE];
	int			bytes_read;
	int			ind;

	bytes_read = 0;
	fd = open(dir, O_RDONLY);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	ind = get_line(id, buffer);
	if (ind == 0)
		return (0);
	if (bytes_read < 0)
		return (0);
	while (buffer[ind] == ' ' || buffer[ind] == '\t' || buffer[ind] == '\n'
		|| buffer[ind] == '\v' || buffer[ind] == '\f' || buffer[ind] == '\r')
		ind++;
	while (buffer[ind] && (buffer[ind] < '0' || buffer[ind] > '9'))
	{
		if ((buffer[ind] >= 'a' && buffer[ind] <= 'z') || (buffer[ind] >= 'A'
				&& buffer[ind] <= 'Z'))
			write(1, &buffer[ind], 1);
		ind++;
	}
	write(1, "\n", 1);
	close(fd);
	return (1);
}
