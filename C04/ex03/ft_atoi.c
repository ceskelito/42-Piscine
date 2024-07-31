/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:28:28 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/23 16:30:44 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_space(char c)
{
	if (c == ' ' || (c == '\f') || (c == '\n'))
		return (1);
	else if (c == '\r' || (c == '\t') || (c == '\v'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	nb;

	nb = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	while (*str == '+' || (*str == '-'))
		if (*str++ == '-')
			sign *= -1;
	i = 0;
	while (str[i] >= '0' && (str[i] <= '9'))
	{
		if (i != 0)
			nb *= 10;
		nb += (str[i++] - '0');
	}
	return (nb * sign);
}
