/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:00:56 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/14 15:02:15 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CORNER1 'A'
#define CORNER2 'C'
#define DEFAULT 'B'

void	ft_putchar(char c);

void	ft_print(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1 && x > 1 && y > 1))
	{
		ft_putchar(CORNER1);
	}
	else if ((i == 0 && j == x - 1 && x > 1) || (i == y - 1 && j == 0))
	{
		ft_putchar(CORNER2);
	}
	else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
	{
		ft_putchar(DEFAULT);
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x < 1 || y < 1)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_print(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
