/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:12:12 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/02 14:00:29 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

void	ft_sa(int *tab, int fd)
{
	int	a;

	a = tab[0];
	tab[0] = tab[1];
	tab[1] = a;
	if (fd != 0)
		write(fd, "sa\n", 3);
}

void	ft_sb(int *tab, int fd)
{
	int	a;

	a = tab[0];
	tab[0] = tab[1];
	tab[1] = a;
	if (fd != 0)
		write(fd, "sb\n", 3);
}

void	ft_pa(int len, int *tab1, int *tab2, int fd)
{
	int	i;

	if (!tab2[0])
		return ;
	i = len - 1;
	while (--i >= 0)
		tab1[i + 1] = tab1[i];
	tab1[0] = tab2[0];
	while (++i < len - 1)
		tab2[i] = tab2[i + 1];
	tab2[i] = 0;
	if (fd != 0)
		write(fd, "pa\n", 3);
}

void	ft_pb(int len, int *tab1, int *tab2, int fd)
{
	int	i;

	if (!tab1[0])
		return ;
	i = len - 1;
	while (--i >= 0)
		tab2[i + 1] = tab2[i];
	tab2[0] = tab1[0];
	while (++i < len - 1)
		tab1[i] = tab1[i + 1];
	tab1[i] = 0;
	if (fd != 0)
		write(fd, "pb\n", 3);
}

void	ft_rr(int *tab1, int *tab2, int fd)
{
	ft_ra(tab1, 0);
	ft_rb(tab2, 0);
	if (fd != 0)
		write(fd, "rr\n", 3);
}
