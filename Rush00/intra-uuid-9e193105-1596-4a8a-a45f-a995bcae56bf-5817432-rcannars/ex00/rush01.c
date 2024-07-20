/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evera <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:17:31 by evera             #+#    #+#             */
/*   Updated: 2024/07/14 14:50:12 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CORNER_LEFT '/'
#define CORNER_RIGHT '\\'
#define DEFAULT '*'

void	ft_putchar(char c);

void	ft_print(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == y - 1 && j == x - 1 && x > 1 && y > 1))
	{
		ft_putchar(CORNER_LEFT);
	}
	else if ((i == 0 && j == x - 1 && x > 1) || (i == y - 1 && j == 0))
	{
		ft_putchar(CORNER_RIGHT);
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
