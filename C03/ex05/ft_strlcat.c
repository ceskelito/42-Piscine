/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:31:18 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/18 18:08:39 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (j++ < (int)size)
		if (*src)
			dest[i++] = *src++;
	dest[i] = '\0';
	i = 0;
	while (dest[i++] != '\0')
		;
	return (i - 1);
}
