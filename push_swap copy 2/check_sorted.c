/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:56:09 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 22:21:57 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_table *m)
{
	free(m->a.tab);
	free(m->b.tab);
}

int	ft_search_max(t_table *m)
{
	t_int	var;

	var.i = 1;
	var.k = m->b.tab[0];
	while (var.i < m->b.used)
	{
		if (var.k < m->b.tab[var.i])
			var.k = m->b.tab[var.i];
		(var.i)++;
	}
	var.i = 0;
	while (var.i < m->b.used)
	{
		if (var.k == m->b.tab[var.i])
			break ;
		(var.i)++;
	}
	return (var.i);
}

void	ft_send(t_table *m)
{
	t_int	var;

	var.i = ft_search_max(m);
	if (var.i <= m->b.used / 2 && var.i > 0)
	{
		while (ft_search_max(m) != 1)
			rb(m, var, 1);
		rb(m, var, 1);
	}
	if (var.i > m->b.used / 2)
		while (ft_search_max(m) != 0)
			rrb(m, var, 1);
	pa(m, var);
}

int	ft_check_sorted(t_table *m)
{
	t_int	var;

	var.i = 0;
	while (var.i < m->a.used - 1)
	{
		if (m->a.tab[var.i] > m->a.tab[(var.i) + 1])
			return (0);
		(var.i)++;
	}
	return (1);
}

void	ft_big_sort2(t_table *m, t_int *var, int *tab)
{
	while (var->p <= var->pivot_3)
	{
		if (m->a.tab[var->j] <= tab[var->pivot_3])
		{
			if (m->b.used > 1)
			{
				if (m->b.tab[0] <= tab[var->pivot_2]
					&& m->a.tab[0] > tab[var->pivot_3])
				{
					rr(m, (*var));
					var->j--;
				}
				else if (m->b.tab[0] <= tab[var->pivot_2])
					rb(m, (*var), 1);
			}
			while (var->j-- != 0)
				ra(m, (*var), 1);
			if (m->a.tab[0] <= tab[var->pivot_3])
			{
				pb(m, (*var));
				(var->p)++;
			}
		}
		var->j++;
	}
}
