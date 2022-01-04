/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_needs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:15:43 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/04 11:54:40 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

int	ft_atoi(char *a)
{
	int	i;
	int	c;
	int	p;

	i = 0;
	c = 0;
	p = 1;
	if (!a || !a[0])
		return (0);
	if (a[i] == '-')
	{
		p = -1;
		i++;
	}
	while (a[i])
	{
		c = c * 10 + (a[i] - '0');
		i++;
	}
	return (c * p);
}

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

int	ft_abs(int a)
{
	if (a < 0)
		a = -1 * a;
	return (a);
}

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
	if (len - i < i)
		return (0);
	return (1);
}
