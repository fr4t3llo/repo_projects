/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:54:23 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 21:54:47 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr(t_table *m, t_int var)
{
	rra(m, var);
	rrb(m, var);
}

void	ft_unknown_move(t_table *m)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_stack_bonus(m);
	exit(1);
}
