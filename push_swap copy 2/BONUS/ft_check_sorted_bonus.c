/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:49:47 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 21:50:11 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_stack_bonus(t_table *m)
{
	free(m->a.tab);
	free(m->b.tab);
}

int	ft_check_sorted_bonus(t_table *m)
{
	t_int	var;

	var.i = 0;
	if (m->b.used != 0)
		return (0);
	while (var.i < m->a.used - 1)
	{
		if (m->a.tab[var.i] > m->a.tab[(var.i) + 1])
			return (0);
		(var.i)++;
	}
	return (1);
}
