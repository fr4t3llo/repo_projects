/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:45:46 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 22:25:19 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_five(t_table *m)
{
	t_int	var;

	var.i = ft_search_min(m);
	if (var.i <= 2 && var.i > 0)
	{
		while (ft_search_min(m) != 1)
			ra(m, var, 1);
		ra(m, var, 1);
	}
	if (var.i > 2)
		while (ft_search_min(m) != 0)
			rra(m, var, 1);
	if (ft_check_sorted(m) == 1)
		return (ft_free_stack(m));
	pb(m, var);
	ft_four(m);
	pa(m, var);
}

void	ft_six_ten(t_table *m)
{
	t_int	var;

	var.i = ft_search_min(m);
	if (var.i <= m->a.used / 2 && var.i > 0)
	{
		while (ft_search_min(m) != 1)
			ra(m, var, 1);
		ra(m, var, 1);
	}
	if (var.i > m->a.used / 2)
		while (ft_search_min(m) != 0)
			rra(m, var, 1);
	if (ft_check_sorted(m) == 1)
		return (ft_free_stack(m));
	pb(m, var);
	if (m->a.used == 5)
		ft_five(m);
	else
		ft_six_ten(m);
	pa(m, var);
}
