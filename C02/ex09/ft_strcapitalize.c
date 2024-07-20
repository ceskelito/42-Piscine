/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:33:17 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/17 17:38:34 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_included(char str_i, char a, char b)
{
	if ((str_i >= a) && (str_i <= b))
		return (true);
	return (false);
}

bool	is_low(char str_i)
{
	if (is_included(str_i, 'a', 'z'))
		return (true);
	return (false);
}

bool	is_up(char str_i)
{
	if (is_included(str_i, 'A', 'Z'))
		return (true);
	return (false);
}

bool	is_alpha(char str_i)
{
	if (is_low(str_i) || is_up(str_i))
		return (true);
	return (false);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (is_alpha(str[i - 1]))
		{
			if (is_up(str[i]))
				str[i] += 32;
		}
		else
		{
			if (!is_included(str[i - 1], '0', '9'))
			{
				if (is_low(str[i]))
					str[i] -= 32;
			}
			else if (is_up(str[i]))
				str[i] += 32;
		}
		i++;
	}
	if (is_low(str[0]))
		str[0] -= 32;
	return (str);
}
