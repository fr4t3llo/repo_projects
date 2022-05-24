/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:35:22 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 22:24:12 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_table *m, t_int var, int id)
{
	if (m->a.used < 2)
		return ;
	var.i = m->a.tab[0];
	var.j = 1;
	while (var.j < m->a.used)
	{
		m->a.tab[(var.j) - 1] = m->a.tab[var.j];
		(var.j)++;
	}
	m->a.tab[var.j - 1] = var.i;
	if (id)
		ft_printf("ra\n");
}

void	rb(t_table *m, t_int var, int id)
{
	if (m->b.used < 2)
		return ;
	var.i = m->b.tab[0];
	var.j = 1;
	while (var.j < m->b.used)
	{
		m->b.tab[(var.j) - 1] = m->b.tab[var.j];
		(var.j)++;
	}
	m->b.tab[var.j - 1] = var.i;
	if (id)
		ft_printf("rb\n");
}

void	rr(t_table *m, t_int var)
{
	ra(m, var, 0);
	rb(m, var, 0);
	ft_printf("rr\n");
}

void	rra(t_table *m, t_int var, int id)
{
	if (m->a.used < 2)
		return ;
	var.i = m->a.tab[(m->a.used) - 1];
	var.j = (m->a.used) - 1;
	while (var.j != 0)
	{
		(var.j)--;
		m->a.tab[(var.j) + 1] = m->a.tab[var.j];
	}
	m->a.tab[var.j] = var.i;
	if (id)
		ft_printf("rra\n");
}

void	rrb(t_table *m, t_int var, int id)
{
	if (m->b.used < 2)
		return ;
	var.i = m->b.tab[(m->b.used) - 1];
	var.j = (m->b.used) - 1;
	while (var.j != 0)
	{
		(var.j)--;
		m->b.tab[(var.j) + 1] = m->b.tab[var.j];
	}
	m->b.tab[var.j] = var.i;
	if (id)
		ft_printf("rrb\n");
}
