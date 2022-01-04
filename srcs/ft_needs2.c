/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_needs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:16:11 by mlagrang          #+#    #+#             */
/*   Updated: 2021/12/29 09:58:04 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

void	ft_prep(int *tab1, int *tab2, char **tabc, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tab1[i] = ft_vn(tabc, i + 1);
		i++;
	}
	tab1[i] = 0;
	i = 0;
	while (i < len)
	{
		tab2[i] = 0;
		i++;
	}
	tab2[i] = 0;
}

int	ft_lastc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 1);
}

int	ft_isnb(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!(tab[i] >= '0' && tab[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_verif(int ac, char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (!ft_isnb(tab[i]))
			return (0);
		j = 1;
		while (j < ac && ft_atoi(tab[i]) != ft_atoi(tab[j]))
			j++;
		if (ft_atoi(tab[i]) == ft_atoi(tab[j]) && i != j)
			return (0);
		i++;
	}
	return (1);
}

int	ft_vn(char **tab, int i)
{
	int	j;
	int	nb;

	j = 1;
	nb = 0;
	while (tab[j])
	{
		if (ft_abs(ft_atoi(tab[j])) < ft_abs(ft_atoi(tab[i])))
			nb++;
		j++;
	}
	return (nb + 1);
}
