/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:41:50 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/17 15:44:01 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	is_included(char str_i, char a, char b)
{
	if ((str_i >= a) && (str_i <= b))
		return (true);
	return (false);
}

bool	is_up(char str_i)
{
	if (is_included(str_i, 'A', 'Z'))
		return (true);
	return (false);
}

int	size_of(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	char_to_hex(char c)
{
	char	dec;
	char	hex[10];
	char	hex_final[10];
	int		remainder;
	int		i;

	dec = (int)c;
	i = 0;
	if (dec == 0)
		return ;
	while (dec > 0)
	{
		remainder = dec % 16;
		if (remainder < 10)
			hex[i++] = remainder + '0';
		else
			hex[i++] = remainder + 'A' - 10;
		dec /= 16;
	}
	hex[i] = '\0';
	i = 0;
	hex_final[i++] = '\\';
	if (size_of(hex) == 1)
		hex_final[i++] = '0';
	while (hex[i] != '\0')
	{
		hex_final[i] = hex[i];
		i++;
	}
	hex_final[i] = '\0';
	i = 0;
	while (hex_final[i] != '\0')
	{
		if (is_up(hex_final[i]))
			hex_final[i] += 32;
		write(1, &hex_final[i++], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 32) && (str[i] <= 126)))
			char_to_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
