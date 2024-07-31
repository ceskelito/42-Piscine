/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:46:07 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/23 12:13:39 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	ris;
	int	subris;

	ris = 1;
	if (power == 0)
	{
		if (nb == 0)
			return (1);
		return (ris);
	}
	if (power < 0)
		return (0);
	subris = ft_recursive_power(nb, power - 1);
	ris = subris * nb;
	return (ris);
}
