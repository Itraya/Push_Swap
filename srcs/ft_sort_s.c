/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:36:18 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/04 11:07:30 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

void	ft_small_first(int *tab1, int fd)
{
	int	i;
	int	l;

	i = 0;
	l = tab1[0];
	while (tab1[i])
	{
		if (tab1[i] < l)
			l = tab1[i];
		i++;
	}
	i = ft_closeup(tab1, l);
	while (i-- > 0)
		ft_ra(tab1, fd);
	i++;
	while (i++ < 0)
		ft_rra(tab1, fd);
}

int	ft_sorted(int *tab1, int *tab2)
{
	int	i;

	i = 0;
	while (tab2[i])
		i++;
	if (i != 0)
		return (0);
	while (tab1[i + 1])
	{
		if (tab1[i] > tab1[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_s(int *tab1, int *tab2, int len, int fd)
{
	int	i;

	i = 0;
	if (ft_sorted(tab1, tab2))
		return ;
	while (ft_last(tab1) > 2)
		ft_pb(len, tab1, tab2, fd);
	ft_trois(tab1, fd);
	ft_solve_end_5(tab1, tab2, len, fd);
	ft_small_first(tab1, fd);
}

int	*prep_sort_s(char **tab, int fd)
{
	int	len;
	int	*tab1;
	int	*tab2;

	len = ft_lastc(tab);
	tab1 = malloc(sizeof(int) * (len + 1));
	tab2 = malloc(sizeof(int) * (len + 1));
	ft_prep(tab1, tab2, tab, len);
	ft_sort_s(tab1, tab2, len, fd);
	free(tab2);
	return (tab1);
}
