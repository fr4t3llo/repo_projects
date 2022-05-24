/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:57:03 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 21:57:25 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check(t_table *m)
{
	if (ft_check_sorted_bonus(m) == 1)
	{
		ft_free_stack_bonus(m);
		ft_printf("OK\n");
		exit(0);
	}
	else
	{
		ft_free_stack_bonus(m);
		ft_printf("KO\n");
		exit(0);
	}
}

void	ft_ifs(t_table *m, t_int var, char *tab)
{
	if (ft_strncmp(tab, "sa\n", 3) == 0)
		sa(m, var);
	else if (ft_strncmp(tab, "sb\n", 3) == 0)
		sb(m, var);
	else if (ft_strncmp(tab, "ss\n", 3) == 0)
		ss(m, var);
	else if (ft_strncmp(tab, "pa\n", 3) == 0)
		pa(m, var);
	else if (ft_strncmp(tab, "pb\n", 3) == 0)
		pb(m, var);
	else if (ft_strncmp(tab, "ra\n", 3) == 0)
		ra(m, var);
	else if (ft_strncmp(tab, "rb\n", 3) == 0)
		rb(m, var);
	else if (ft_strncmp(tab, "rr\n", 3) == 0)
		rr(m, var);
	else if (ft_strncmp(tab, "rra\n", 4) == 0)
		rra(m, var);
	else if (ft_strncmp(tab, "rrb\n", 4) == 0)
		rrb(m, var);
	else if (ft_strncmp(tab, "rrr\n", 4) == 0)
		rrr(m, var);
	else
		ft_unknown_move(m);
}

void	ft_malloc_bonus(void *tab, int *hub, int *t, char **str)
{
	int	i;

	i = 0;
	if (tab == NULL)
	{
		ft_putstr_fd("malloc error\n", 2);
		free(hub);
		free(t);
		while (str[i] != NULL)
			free(str[i++]);
		free(str);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_table	m;
	char	*tab;
	t_int	var;

	if (ac == 1)
		return (0);
	var.i = 0;
	m.a.size = ft_checknumbers_bonus(av);
	m.a.tab = ft_double_bonus(av, m.a.size);
	m.a.used = m.a.size;
	m.b.size = m.a.size;
	m.b.tab = (int *)malloc(m.b.size * sizeof(int));
	ft_malloc_bonus(m.b.tab, m.a.tab, NULL, NULL);
	m.b.used = 0;
	tab = get_next_line(0);
	while (tab)
	{
		ft_ifs(&m, var, tab);
		free(tab);
		tab = get_next_line(0);
	}
	ft_check(&m);
	return (0);
}
