/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_needs3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:55:18 by mlagrang          #+#    #+#             */
/*   Updated: 2021/12/29 08:40:36 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

void	ft_search(int *tab, int *minmax, int len)
{
	int	i;

	i = ft_closeup(tab, minmax[1]);
	if (ft_abs(ft_closeup(tab, minmax[0])) < ft_abs(ft_closeup(tab, minmax[1])))
		i = ft_closeup(tab, minmax[0]);
	while (i-- > 0)
		ft_rb(len, tab, minmax[3]);
	i++;
	while (i++ < 0)
		ft_rrb(tab, minmax[3]);
}

void	ft_putend(int *tab, int *minmax)
{
	int	i;

	i = 0;
	while (tab[i] != minmax[2])
		i++;
	if (i > (ft_last(tab) / 2))
		while (tab[ft_last(tab)] != minmax[2])
			ft_rra(tab, minmax[3]);
	else
		while (tab[ft_last(tab)] != minmax[2])
			ft_ra(tab, minmax[3]);
}
