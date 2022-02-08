/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:27:48 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/02 13:59:37 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_PS.h"

void	ft_ra(int *tab, int fd)
{
	int	a;
	int	i;

	i = -1;
	a = tab[0];
	while (++i < ft_last(tab))
		tab[i] = tab[i + 1];
	tab[ft_last(tab)] = a;
	if (fd != 0)
		write(fd, "ra\n", 3);
}

void	ft_rb(int *tab, int fd)
{
	int	a;
	int	i;

	i = -1;
	a = tab[0];
	while (++i < ft_last(tab))
		tab[i] = tab[i + 1];
	tab[ft_last(tab)] = a;
	if (fd != 0)
		write(fd, "rb\n", 3);
}

void	ft_rra(int *tab, int fd)
{
	int	a;
	int	i;

	i = ft_last(tab);
	a = tab[i];
	while (--i >= 0)
		tab[i + 1] = tab[i];
	tab[0] = a;
	if (fd != 0)
		write(fd, "rra\n", 4);
}

void	ft_rrb(int *tab, int fd)
{
	int	a;
	int	i;

	i = ft_last(tab);
	a = tab[i];
	while (--i >= 0)
		tab[i + 1] = tab[i];
	tab[0] = a;
	if (fd != 0)
		write(fd, "rrb\n", 4);
}

void	ft_rrr(int *tab1, int *tab2, int fd)
{
	ft_rra(tab1, 0);
	ft_rrb(tab2, 0);
	if (fd != 0)
		write(fd, "rrr\n", 4);
}
