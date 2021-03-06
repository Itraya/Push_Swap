/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_PS.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:12:38 by mlagrang          #+#    #+#             */
/*   Updated: 2022/02/03 10:59:11 by mlagrang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PS_H
# define FT_PS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

void	ft_sa(int *tab, int fd);
void	ft_sb(int *tab, int fd);
void	ft_pa(int len, int *tab1, int *tab2, int fd);
void	ft_pb(int len, int *tab1, int *tab2, int fd);
void	ft_ra(int *tab, int fd);
void	ft_rb(int *tab, int fd);
void	ft_rr(int *tab1, int *tab2, int fd);
void	ft_rra(int *tab, int fd);
void	ft_rrb(int *tab, int fd);
void	ft_rrr(int *tab1, int *tab2, int fd);
int		ft_last(int *tab);
void	ft_prep(int *tab1, int *tab2, char **tabc, int len);
void	ft_putend(int *tab1, int *tab2, int *minmax);
int		ft_lastc(char **tab);
int		ft_verif(int ac, char **tab);
int		ft_vn(char **tab, int i);
void	ft_search(int *tab, int *minmax);
void	ft_sort_b(int *minmax, int *tab1, int *tab2, int len);
void	ft_nb_sort(int *minmax, int len, int *tab1, int *tab2);
void	ft_s_end(int *tab, int len, int fd);
void	ft_sort_l(int *t, int *tab1, int *tab2, int fd);
int		*prep_sort_l(char **tab, int u, int fd);
int		*prep_sort_s(char **tab, int fd);
void	ft_trois(int *tab, int fd);
int		ft_is_biggest(int *tab1, int *tab2);
int		ft_is_smallest(int *tab1, int *tab2);
void	ft_good_place(int *tab1, int *tab2, int fd);
void	ft_solve_end_5(int *tab1, int *tab2, int len, int fd);
int		ft_atoi(char *a);
int		ft_fl(char **tab);
int		ft_abs(int a);
int		ft_smolcloseup(int *tab, int *minmax);
int		ft_closeup(int *tab, int val);
int		ft_closer(int *tab, int min, int max, int len);
char	**ft_split(char *s, char c);
void	ft_small_first(int *tab1, int fd);
int		ft_len(char **a);
int		ft_isatoi(char *a);
int		ft_sorted(int *tab1, int *tab2);
void	ft_free(char **a);

#endif
