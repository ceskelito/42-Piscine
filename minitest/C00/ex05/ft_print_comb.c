/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:25:50 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/15 15:13:23 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nmb(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if ((a == '7') && (b == '8') && (c == '9'))
	{
	}
	else
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		c = a + 2;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				print_nmb(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
