/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:23:28 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/28 23:36:08 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	dict_error(void)
{
	write(1, "dictErorr\n", 10);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

void	ft_reverse_str(char *str)
{
	int		i;
	int		size;
	char	tmp;

	i = 0;
	size = ft_strlen(str);
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
}

void	find_key(char *str)
{
	int		i;
	char	key[4];

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (i == 0)
		{
			if (!print(ft_strncpy(&key, str, i, 1)))
				return (dict_error());
		}
		else if ((i % 3 == 2) && (str[i] != '0'))
		{
			if (!hundreds(str, i))
				return (dict_error());
		}
		else if ((i % 3 == 1) && (str[i] != '0'))
		{
			if (!tens(str, &i))
				return (dict_error());
		}
		else if (i % 3 == 0)
		{
			if (!units(str, i))
				return (dict_error());
		}
		i--;
	}
}
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char *argv[])
{
	char	*nbr;
	int		i;

	nbr = argv[1];
	ft_putstr(nbr);
	ft_putstr("\n");
	ft_reverse_str(nbr);
	find_key(nbr);
	i = 0;
	return (0);
}
