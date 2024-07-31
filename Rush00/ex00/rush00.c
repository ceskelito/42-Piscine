/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:00:56 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/14 14:48:07 by evera            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CORNER 'o'
#define HORIZONTAL '-'
#define VERTICAL '|'

void	ft_putchar(char c);

void	ft_print(int i, int j, int x, int y)
{
	if ((i == 0 || i == y - 1) && (j == 0 || j == x - 1))
	{
		ft_putchar(CORNER);
	}
	else if (i == 0 || i == y - 1)
	{
		ft_putchar(HORIZONTAL);
	}
	else if (j == 0 || j == x - 1)
	{
		ft_putchar(VERTICAL);
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
