/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:25:01 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 22:25:09 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_min(t_table *m)
{
	t_int	var;

	var.i = 1;
	var.k = m->a.tab[0];
	while (var.i < m->a.used)
	{
		if (var.k > m->a.tab[var.i])
			var.k = m->a.tab[var.i];
		(var.i)++;
	}
	var.i = 0;
	while (var.i < m->a.used)
	{
		if (var.k == m->a.tab[var.i])
			break ;
		(var.i)++;
	}
	return (var.i);
}

void	ft_three(t_table *m)
{
	t_int	var;

	var.i = 0;
	if (m->a.tab[0] > m->a.tab[1])
		ft_two(m);
	if ((ft_check_sorted(m) == 0))
		rra(m, var, 1);
	if (m->a.tab[0] > m->a.tab[1])
		ft_two(m);
}

void	ft_two(t_table *m)
{
	t_int	var;

	var.i = 0;
	sa(m, var, 1);
}

void	ft_four(t_table *m)
{
	t_int	var;

	var.i = ft_search_min(m);
	if (var.i == 1)
		ra(m, var, 1);
	else if (var.i == 2)
	{
		rra(m, var, 1);
		rra(m, var, 1);
	}
	else if (var.i == 3)
		rra(m, var, 1);
	if (ft_check_sorted(m) == 1)
		return (ft_free_stack(m));
	pb(m, var);
	ft_three(m);
	pa(m, var);
}

void	ft_sorting(t_table *m, int ac)
{
	if (ac == 2)
		ft_two(m);
	else if (ac == 3)
		ft_three(m);
	else if (ac == 4)
		ft_four(m);
	else if (ac == 5)
		ft_five(m);
	else if (ac >= 6 && ac <= 10)
		ft_six_ten(m);
	else if (ac > 10 && ac <= 100)
		ft_big_sort(m, 3);
	else if (ac > 100 && ac <= 500)
		ft_big_sort(m, 7);
}
