/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:15:35 by mlagrang          #+#    #+#             */
/*   Updated: 2022/01/04 12:07:52 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_PS.h"

char	*ft_strcpy(char *a)
{
	char	*r;
	int		i;

i = 0;
	while (a[i])
		i++;
	r = malloc(i + 1);
	i = -1;
	while (a[++i])
		r[i] = a[i];
	r[i] = '\0';
	return (r);
}

void	ft_free(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

int	main(int ac, char **av)
{
	int		*t;
	char	**c;

	if (ac == 1)
		return (0);
	c = av;
	if (ac == 2)
	{
		c = ft_split(av[1], ' ');
		c[0] = ft_strcpy(av[0]);
	}
	if (ft_verif(ft_len(c) - 1, c))
	{
		if (ac - 1 > 400)
			t = prep_sort_l(c, ((ac - 1) / 10), 1);
		else if (ac - 1 > 5)
			t = prep_sort_l(c, (ac - 1) / 5, 1);
		else
			t = prep_sort_s(c, 1);
		free(t);
	}
	else
		write(1, "Error\n", 6);
	if (c != av)
		ft_free(c);
}
