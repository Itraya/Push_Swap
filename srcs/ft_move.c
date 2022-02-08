/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:01:37 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/08 10:02:16 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

int	ft_fl(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i][0] != '\0')
	{
		if (tab[j] < tab[i])
			j = i;
		i++;
	}
	return (j);
}

void	ft_putend(int *tab1, int *tab2, int *minmax)
{
	int	i;

	i = 0;
	while (tab1[i] != minmax[2])
		i++;
	if (i > (ft_last(tab1) / 2))
	{
		while (tab1[ft_last(tab1)] != minmax[2])
		{
			if (ft_smolcloseup(tab2, minmax) < 0)
				ft_rrr(tab1, tab2, minmax[3]);
			else
				ft_rra(tab1, minmax[3]);
		}
	}
	else
	{
		while (tab1[ft_last(tab1)] != minmax[2])
		{
			if (ft_smolcloseup(tab2, minmax) > 0)
				ft_rr(tab1, tab2, minmax[3]);
			else
				ft_ra(tab1, minmax[3]);
		}
	}
}

int	ft_last(int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i - 1);
}
