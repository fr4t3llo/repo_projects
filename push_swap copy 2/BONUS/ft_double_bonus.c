/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:52:00 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 21:52:25 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_cont1_bonus(char **num, t_int *ints, int *tab)
{
	while (num[ints->j])
	{
		ints->p = 0;
		ints->k = ft_atoi_custom_bonus(num[ints->j], num);
		while (ints->p < ints->l)
		{
			if (tab[ints->p] == ints->k)
			{
				free(tab);
				ft_free_all_bonus(num);
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			(ints->p)++;
		}
		tab[ints->l] = ints->k;
		(ints->l)++;
		(ints->j)++;
	}
}

void	ft_error_bonus(char **num)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_all_bonus(num);
	exit(1);
}

int	ft_atoi_custom_bonus(const	char	*str, char **num)
{
	int			i;
	int			sign;
	long int	r;

	i = 0;
	sign = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	if ((r * sign) > 2147483647 || (r * sign) < -2147483648)
		ft_error_bonus(num);
	return (sign * r);
}

int	*ft_double_bonus(char **av, int sum)
{
	t_int	ints;
	char	**num;
	int		*tab;

	ints.i = 1;
	num = NULL;
	ints.k = 0;
	ints.l = 0;
	ints.p = 0;
	tab = (int *)malloc(sum * sizeof(int));
	ft_malloc_bonus(tab, NULL, NULL, NULL);
	while (av[ints.i])
	{
		ints.j = 0;
		num = ft_split(av[ints.i], 32);
		ft_malloc_bonus(NULL, NULL, NULL, num);
		ft_cont1_bonus(num, &ints, tab);
		ft_free_all_bonus(num);
		(ints.i)++;
	}
	return (tab);
}
