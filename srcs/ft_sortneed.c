/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortneed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:53:16 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/04 12:09:08 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

void	ft_trois(int *tab, int fd)
{
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		ft_sa(tab, fd);
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		ft_sa(tab, fd);
		ft_rra(tab, fd);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		ft_ra(tab, fd);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		ft_sa(tab, fd);
		ft_ra(tab, fd);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		ft_rra(tab, fd);
}

int	ft_is_biggest(int *tab1, int *tab2)
{
	int	i;

	i = 0;
	while (tab1[i])
	{
		if (tab1[i] > tab2[0])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_smallest(int *tab1, int *tab2)
{
	int	i;

	i = 0;
	while (tab1[i])
	{
		if (tab1[i] < tab2[0])
			return (0);
		i++;
	}
	if (tab2[1] < tab2[0] && tab2[1] != 0)
		return (0);
	return (1);
}

void	ft_good_place(int *tab1, int *tab2, int fd)
{
	int	up;
	int	dn;
	int	i;

	up = 0;
	dn = 0;
	i = -1;
	while (tab1[++i])
	{
		if (tab1[i] == tab2[0] + 1)
			up = tab1[i];
		if (tab1[i] == tab2[0] - 1)
			dn = tab1[i];
	}
	i = ft_closeup(tab1, dn);
	if ((ft_abs(ft_closeup(tab1, up)) < ft_abs(ft_closeup(tab1, dn))
			&& up != 0) || dn == 0)
		i = ft_closeup(tab1, up);
	while (i-- > 0)
		ft_ra(tab1, fd);
	i++;
	while (i++ < 0)
		ft_rra(tab1, fd);
	if (i == 0)
		ft_sa(tab1, fd);
}

void	ft_solve_end_5(int *tab1, int *tab2, int len, int fd)
{
	int	i;

	i = 0;
	while (++i <= len)
	{
		if (ft_is_biggest(tab1, tab2))
		{
			ft_small_first(tab1, fd);
			ft_pa(len, tab1, tab2, fd);
			ft_ra(tab1, fd);
		}
		else if (ft_is_smallest(tab1, tab2))
		{
			ft_small_first(tab1, fd);
			ft_pa(len, tab1, tab2, fd);
		}
		else
		{
			ft_good_place(tab1, tab2, fd);
			ft_pa(len, tab1, tab2, fd);
			if (tab1[0] > tab1[1])
				ft_sa(tab1, fd);
		}
	}
}
