/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:36:29 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/28 23:36:32 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strncpy(char **dest, const char **src, int pos, int n)
{
	size_t	i;

	i = 0;
	while (i < n && (*src)[pos - i] != '\0')
	{
		(*dest)[i] = (*src)[pos - i];
		i++;
	}
	while (i < n + 1)
	{
		(*dest)[i] = '\0';
		i++;
	}
	return (*dest);
}

int	hundreds(char *str, int i)
{
	char	*key;

	if (!print(ft_strncpy(&key, &str, i, 1)))
		return (0);
	if (!print("100"))
		return (0);
	return (1);
}

int	tens(char *str, int *i)
{
	char	*key;

	if (str[*i] == '1')
	{
		if (!print(ft_strncpy(&key, &str, *i, 2)))
			return (0);
		if ((find_class_units(*i / 3)) == 0)
			return (0);
		(*i)--;
	}
	else if (!find_class_tens(str, *i))
		return (0);
	return (1);
}

int	units(char *str, int i)
{
	char	*key;

	if (str[i] != '0')
	{
		if (!print(ft_strncpy(&key, &str, i, 1)))
			return (0);
	}
	if (!(find_class_units(i / 3)))
		return (0);
	return (1);
}
