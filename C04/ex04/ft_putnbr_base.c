/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:19:07 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/29 16:11:36 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

int	check_base(char *base)
{
	int		i;
	char	*temp;
	int		c;

	temp = base;
	if (ft_strlen(base) < 2)
		return (0);
	while (*temp)
	{
		if (*temp == '+' || (*temp == '-'))
			return (0);
		i = 0;
		c = 0;
		while (base[i] != '\0')
			if (base[i++] == *temp)
				c++;
		if (c > 1)
			return (0);
		temp++;
	}
	return (1);
}

void	from_dec(long int nb, char *base)
{
	char	ris;
	int		size;

	size = ft_strlen(base);
	if (nb <= 0)
		return ;
	ris = base[nb % size];
	from_dec(nb / size, base);
	write(1, &ris, 1);
}

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long int	lnb;

	lnb = (long)nb;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	if (lnb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (!(check_base(base)))
		return ;
	from_dec(lnb, base);
}
