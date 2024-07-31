/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:16:57 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/31 13:53:07 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while ((str[i]) != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

int	dest_size(int size, char **src, char *sep)
{
	int	i;
	int	def_size;

	def_size = 0;
	i = 0;
	while (i < size)
	{
		def_size += ft_strlen(src[i]);
		i++;
	}
	def_size += ft_strlen(sep) * (size - 1);
	return (def_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;

	if (size == 0)
		return (NULL);
	dest = (char *)malloc(dest_size(size, strs, sep) * sizeof(char));
	if (dest == NULL)
		return (dest);
	i = 0;
	while (strs[i])
	{
		dest = ft_strcat(dest, strs[i]);
		i++;
		if (i == size)
			break ;
		dest = ft_strcat(dest, sep);
	}
	return (dest);
}
