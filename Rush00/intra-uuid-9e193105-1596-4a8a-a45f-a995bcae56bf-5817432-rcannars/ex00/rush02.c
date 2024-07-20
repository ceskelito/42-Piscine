/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcannars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:47:38 by rcannars          #+#    #+#             */
/*   Updated: 2024/07/14 12:06:19 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOP_CORNER 'A'
#define BOTTOM_CORNER 'C'
#define DEFAULT 'B'

void	ft_putchar(char c);

void	ft_print(int i, int j, int x, int y)
{
	if ((i == 0 && (j == 0 || j == x - 1)))
	{
		ft_putchar(TOP_CORNER);
	}
	else if (i == y - 1 && (j == 0 || j == x - 1))
	{
		ft_putchar(BOTTOM_CORNER);
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
