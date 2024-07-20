/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:13:29 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/15 09:53:48 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

int	set_positive(int nb)
{
	if (nb == (-2147483648))
	{
		ft_putnbr(-2);
		return (147483648);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		return ((nb) * (-1));
	}
	return (nb);
}

int	set_div(int nb, int div)
{
	if (div == 1000000000)
		return (div);
	div *= 10;
	if (nb / div < 1)
	{
		div /= 10;
		return (div);
	}
	set_div(nb, div);
}

void	print(int n)
{
	char	c;

	c = '0' + n;
	write(1, &c, 1);
}

void	print_digit(int nb, int div)
{
	int	d;

	d = (nb - (nb % div)) / div;
	if (div == 1)
	{
		print(d);
		return ;
	}
	print(d);
	print_digit(nb - (d * div), div / 10);
}

void	ft_putnbr(int nb)
{
	int	div;

	nb = set_positive(nb);
	div = set_div(nb, 1);
	print_digit(nb, div);
}
