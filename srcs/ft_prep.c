/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:59:59 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/08 10:01:07 by mlagrang         ###   ########.fr       */
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

int	ft_isnb(char *tab)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (tab[i] == '-')
		i++;
	while (tab[i])
	{
		if (!(tab[i] >= '0' && tab[i] <= '9'))
		{
			return (0);
		}
		else
			nb = 1;
		i++;
	}
	if (nb == 0)
		return (0);
	return (1);
}

int	ft_verif(int ac, char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (i <= ac)
	{
		if (!ft_isnb(tab[i]) || !ft_isatoi(tab[i]))
		{
			ft_free(tab);
			return (0);
		}
		j = 1;
		while (j < ac && ft_atoi(tab[i]) != ft_atoi(tab[j]))
			j++;
		if (ft_atoi(tab[i]) == ft_atoi(tab[j]) && i != j)
		{
			ft_free(tab);
			return (0);
		}
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
		if (ft_atoi(tab[j]) < ft_atoi(tab[i]))
			nb++;
		j++;
	}
	return (nb + 1);
}

int	ft_isatoi(char *a)
{
	int			i;
	long int	c;
	int			p;

	i = 0;
	c = 0;
	p = 1;
	if (!a || !a[0])
	{
		return (0);
	}
	if (a[i] == '-')
	{
		p = -1;
		i++;
	}
	while (a[i])
	{
		c = c * 10 + (a[i] - '0');
		if (c * p > INT_MAX || c * p < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
