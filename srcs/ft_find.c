/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:54:06 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/08 09:58:11 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

int	ft_closeup(int *tab, int val)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	while (tab[i] != val)
	{
		i++;
	}
	if (ft_abs(i - len) > ft_abs(i))
		return (i);
	return (i - len);
}

int	ft_closer(int *tab, int min, int max, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < max - min)
	{
		if (tab[i] >= min && tab[i] <= max)
			j++;
		i++;
	}
	if (len - i < i - max - min)
		return (0);
	return (1);
}

int	ft_lastc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 1);
}

void	ft_search(int *tab, int *minmax)
{
	int	i;

	i = ft_closeup(tab, minmax[1]);
	if (ft_abs(ft_closeup(tab, minmax[0])) < ft_abs(ft_closeup(tab, minmax[1])))
		i = ft_closeup(tab, minmax[0]);
	while (i-- > 0)
		ft_rb(tab, minmax[3]);
	i++;
	while (i++ < 0)
		ft_rrb(tab, minmax[3]);
}

int	ft_smolcloseup(int *tab, int *minmax)
{
	int	i;

	if (tab[0] == minmax[0] || tab[0] == minmax[1])
		return (0);
	i = ft_closeup(tab, minmax[1]);
	if (ft_abs(ft_closeup(tab, minmax[0])) < ft_abs(ft_closeup(tab, minmax[1])))
		i = ft_closeup(tab, minmax[0]);
	return (i);
}
