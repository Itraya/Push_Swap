/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:15:35 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/02 10:19:42 by mlagrang         ###   ########.fr       */
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

int	ft_lac(char **av)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	nb = 0;
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
			nb++;
		i++;
	}
	return (nb);
}

char	*ft_cjoin(char **av, int ac)
{
	int		i;
	int		j;
	int		nb;
	char	*s;

	s = malloc(ft_lac(av) + ac);
	i = 1;
	nb = -1;
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
			s[++nb] = av[i][j];
		s[++nb] = ' ';
		i++;
	}
	s[nb + 1] = '\0';
	return (s);
}

int	main(int ac, char **av)
{
	int		*t;
	char	**c;
	char	*a;

	if (ac == 1)
		return (0);
	a = ft_cjoin(av, ac);
	c = ft_split(a, ' ');
	c[0] = ft_strcpy(av[0]);
	if (ft_verif(ft_len(c) - 1, c))
	{
		if (ac - 1 > 400)
			t = prep_sort_l(c, ((ac - 1) / 10), 1);
		else if (ac - 1 > 5)
			t = prep_sort_l(c, (ac - 1) / 5, 1);
		else
			t = prep_sort_s(c, 1);
		if (t == NULL)
			return (0);
		free(t);
	}
	else
		write(1, "Error\n", 6);
	ft_free(c);
}
