/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:56:20 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 22:23:58 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_table *m, t_int var, int id)
{
	if (m->a.used < 2)
		return ;
	var.i = m->a.tab[0];
	m->a.tab[0] = m->a.tab[1];
	m->a.tab[1] = var.i;
	if (id)
		ft_printf("sa\n");
}

void	sb(t_table *m, t_int var, int id)
{
	if (m->b.used < 2)
		return ;
	var.i = m->b.tab[0];
	m->b.tab[0] = m->b.tab[1];
	m->b.tab[1] = var.i;
	if (id)
		ft_printf("sb\n");
}

void	ss(t_table *m, t_int var)
{
	sa(m, var, 0);
	sb(m, var, 0);
	ft_printf("ss\n");
}

void	pa(t_table *m, t_int var)
{
	if (m->b.used == 0)
		return ;
	var.i = m->b.tab[0];
	var.j = m->a.used + 1;
	while (--var.j != 0)
	{
		if (var.j == 1)
		{
			m->a.tab[(var.j)] = m->a.tab[(var.j) - 1];
			break ;
		}
		var.k = m->a.tab[(var.j) - 1];
		m->a.tab[(var.j) - 1] = m->a.tab[(var.j) - 2];
		m->a.tab[(var.j)] = var.k;
	}
	var.k = 0;
	while (var.k <= m->b.used)
	{
		m->b.tab[(var.k)] = m->b.tab[(var.k) + 1];
		(var.k)++;
	}
	m->a.tab[0] = var.i;
	(m->b.used)--;
	(m->a.used)++;
	ft_printf("pa\n");
}

void	pb(t_table *m, t_int var)
{
	if (m->a.used == 0)
		return ;
	var.i = m->a.tab[0];
	var.j = m->b.used + 1;
	while (--var.j != 0)
	{
		if (var.j == 1)
		{
			m->b.tab[(var.j)] = m->b.tab[(var.j) - 1];
			break ;
		}
		var.k = m->b.tab[(var.j) - 1];
		m->b.tab[(var.j) - 1] = m->b.tab[(var.j) - 2];
		m->b.tab[(var.j)] = var.k;
	}
	var.k = 0;
	while (var.k <= m->a.used)
	{
		m->a.tab[(var.k)] = m->a.tab[(var.k) + 1];
		(var.k)++;
	}
	m->b.tab[0] = var.i;
	(m->b.used)++;
	(m->a.used)--;
	ft_printf("pb\n");
}
