/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:52:54 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/18 17:44:25 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

bool	complete_cmp(char *str, char *to_find, int i)
{
	to_find = &to_find[0];
	str = &str[i];
	while (*to_find)
		if (*to_find++ != *str++)
			return (false);
	return (true);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
			if (complete_cmp(str, to_find, i))
				return (str + i);
		i++;
	}
	return (NULL);
}
