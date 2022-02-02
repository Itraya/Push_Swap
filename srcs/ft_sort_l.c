/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:44:57 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/02 09:42:03 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

void	ft_sort_b(int *minmax, int *tab1, int *tab2, int len)
{
	while (tab2[0])
	{
		ft_search(tab2, minmax, len);
		ft_pa(len, tab1, tab2, minmax[3]);
		if (tab1[0] == minmax[0])
		{
			ft_ra(tab1, minmax[3]);
			minmax[0]++;
		}
		else
			minmax[1]--;
	}
}

void	ft_nb_sort(int *minmax, int len, int *tab1, int *tab2)
{
	int	j;
	int	s;

	j = 0;
	s = ft_closer(tab1, minmax[0], minmax[1], len);
	while (j < (minmax[1] - minmax[0]) + 1)
	{
		if (tab1[0] >= minmax[0] && tab1[0] <= minmax[1])
		{
			ft_pb(len, tab1, tab2, minmax[3]);
			j++;
		}
		else if (s)
			ft_ra(tab1, minmax[3]);
		else
			ft_rra(tab1, minmax[3]);
	}
	if (minmax[0] != 1)
		ft_putend(tab1, minmax);
	ft_sort_b(minmax, tab1, tab2, len);
}

void	ft_s_end(int *tab, int len, int fd)
{
	int	i;

	i = 0;
	if (tab[i] != 1)
		while (tab[i] < tab[i + 1])
			ft_ra(tab, fd);
	if (tab[i] == len)
		ft_ra(tab, fd);
}

void	ft_sort_l(int *t, int *tab1, int *tab2, int fd)
{
	int	minmax[4];
	int	ret;

	ret = t[1];
	minmax[0] = 1;
	minmax[1] = t[1];
	minmax[3] = fd;
	while (minmax[1] < t[0])
	{
		ft_nb_sort(minmax, t[0], tab1, tab2);
		ret += t[1];
		minmax[0] = ret - t[1] + 1;
		minmax[1] = ret;
		minmax[2] = ret - t[1];
	}
	minmax[1] = t[0];
	ft_nb_sort(minmax, t[0], tab1, tab2);
	ft_s_end(tab1, t[0], minmax[3]);
}

int	*prep_sort_l(char **tab, int u, int fd)
{
	int	t[2];
	int	*tab1;
	int	*tab2;

	t[0] = ft_lastc(tab);
	t[1] = u;
	tab1 = malloc(sizeof(int) * (t[0] + 1));
	if (!tab1)
		return (NULL);
	tab2 = malloc(sizeof(int) * (t[0] + 1));
	if (tab2)
	{
		ft_prep(tab1, tab2, tab, t[0]);
		if (!ft_sorted(tab1, tab2))
			ft_sort_l(t, tab1, tab2, fd);
		free(tab2);
		return (tab1);
	}
	return (NULL);
}
