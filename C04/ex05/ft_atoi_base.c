/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:34:02 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/30 15:27:30 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	l;

	while (str[l])
		l++;
	return (l);
}

int	truncate_errors(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (base[j] && (base[j] != str[i]))
			j++;
		if (base[j] != str[i])
			break ;
		i++;
	}
	str[i] = '\0';
	return (i);
}

int	get_base_lenght(char *base)
{
	int	l;
	int	j;

	l = 0;
	while (base[l])
	{
		if (base[l] == '+' || (base[l] == '-') || base[l] == ' '
			|| (base[l] >= 9 && (base[l] <= 13)))
			return (0);
		j = l;
		while (base[++j])
			if (base[j] == base[l])
				return (0);
		++l;
	}
	return (l);
}

int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		++i;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	ris;
	int	sign;
	int	base_lenght;
	int	i;

	ris = 0;
	sign = 1;
	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || (*str == '+'))
		if (*str++ == '-')
			sign *= (-1);
	str += i;
	truncate_errors(str, base);
	base_lenght = get_base_lenght(base);
	if (base_lenght == 0 || sign == 0)
		return (0);
	while (*str)
	{
		ris = (ris * base_lenght) + get_value(*str, base);
		str++;
	}
	return (ris * sign);
}
