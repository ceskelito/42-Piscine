/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:42:18 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/31 17:00:34 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}	
}

void ft_putnbr(int nb)
{
	char c;
	int div;

	if(nb < 10)
	{
		c = nb + '0';
		write(1, &c,1);
		return;
	}	

	div = 1;
	while(nb / div > 1)
	{
		div *= 10;
	}
	div /= 10;
	ft_putnbr(nb / div);
	ft_putnbr(nb % div);
}

void ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while(par[i].str)
	{
		ft_putnbr((par + i) -> size);
		ft_putstr(par[i].str);
		ft_putstr((par + i) -> copy);
		i++;
	}
}
