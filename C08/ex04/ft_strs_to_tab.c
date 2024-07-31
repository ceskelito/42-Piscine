/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:54:06 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/31 16:56:21 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int ft_strlen(char *str)
{
	int  i;

	i = 0;
	while(*str)
		i++;
	return (i);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i;
	t_stock_str *ptr_stock;

	ptr_stock = (t_stock_str *) malloc(sizeof(t_stock_str) * ac);
	i = 0;
/*	while(i < ac)
	{
		//ptr_stock[i] = (t_stock_str *) malloc(sizeof(t_stock_str));

		(ptr_stock + i) -> size = ft_strlen(av[i]);
		(ptr_stock + i) -> str = av[i];
		(ptr_stock + i) -> copy = av[i];
		i++;
	}*/
	return (ptr_stock);
}
