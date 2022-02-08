/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:58:44 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/08 09:59:37 by mlagrang         ###   ########.fr       */
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

int	ft_abs(int a)
{
	if (a < 0)
		a = -1 * a;
	return (a);
}

int	ft_len(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
