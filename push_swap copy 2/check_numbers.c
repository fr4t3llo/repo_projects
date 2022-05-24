/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:27:45 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 22:22:15 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_over(char **num)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (num[i])
	{
		while (num[i][j] != '\0')
		{
			if (num[i][j] == '-' || num[i][j] == '+')
				j++;
			while (num[i][j] == '0')
				j++;
			while (num[i][j])
			{
				j++;
				n++;
			}
			if (n > 10)
				ft_error(num);
		}
		i++;
	}
}

void	ft_cont(char **num, int k, int j, int *sum)
{
	while (num[k])
	{
		j = ft_count(num, k, j);
		while (num[k][j])
		{
			if (ft_isdigit(num[k][j]) == 0)
				ft_error(num);
			j++;
		}
		k++;
	}
	(*sum) += k;
}

int	ft_count(char **str, int k, int j)
{
	while (str[k][j] == ' ')
		j++;
	if (str[k][j] == '-' || str[k][j] == '+')
		j++;
	return (j);
}

void	ft_free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	ft_checknumbers(char **av)
{
	t_int	var;
	char	**num;
	int		sum;

	var.i = 1;
	sum = 0;
	num = NULL;
	var.j = 0;
	while (av[var.i])
	{
		var.k = 0;
		num = ft_split(av[var.i], 32);
		//ft_malloc(NULL, NULL, NULL, num);
		ft_over(num);
		if (num[var.k] == NULL)
			ft_error(num);
		ft_cont(num, var.k, var.j, &sum);
		ft_free_all(num);
		(var.i)++;
	}
	return (sum);
}

