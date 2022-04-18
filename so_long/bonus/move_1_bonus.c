/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:56:41 by skasmi            #+#    #+#             */
/*   Updated: 2022/04/18 20:01:58 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move_up1(t_map *t, int i, int j)
{
	if (t->str[i - 1][j] == '0')
	{
		t->str[i - 1][j] = 'P';
		t->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", t->moves);
		mlx_string_put(t->mlx_ptr, t->mlx_win, 15, 15, 0x0000000, "hello !!");
		t->moves++;
		return (0);
	}
	if (t->str[i - 1][j] == 'N')
	{
		ft_printf("\033[0;33mYou Lost !!");
		exit(1);
	}
	if (t->str[i - 1][j] == 'C')
	{
		t->str[i - 1][j] = 'P';
		t->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", t->moves);
		mlx_string_put(t->mlx_ptr, t->mlx_win, 15, 15, 0x0000000, "hello !!");
		t->moves++;
		return (0);
	}
	if (t->str[i - 1][j] == '1')
		return (0);
	return (1);
}

void	ft_move_up(t_map *t)
{
	int	i;
	int	j;

	i = -1;
	while (t->str[++i])
	{
		j = 0;
		while (t->str[i][j])
		{
			if (t->str[i][j] == 'P')
			{
				if (ft_move_up1(t, i, j) == 0)
					return ;
				if (t->str[i - 1][j] == 'E')
				{
					if (ft_check_collect(t) == 0)
					{
						ft_printf("\033[0;32m=== YOU WIN ===\n");
						exit(0);
					}
				}
			}
			j++;
		}
	}
}

int	ft_move_left1(t_map *t, int i, int j)
{
	if (t->str[i][j - 1] == '0')
	{
		t->str[i][j - 1] = 'P';
		t->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", t->moves);
		mlx_string_put(t->mlx_ptr, t->mlx_win, 15, 15, 0x0000000, "hello !!");
		t->moves++;
		return (0);
	}
	if (t->str[i][j - 1] == 'N')
	{
		ft_printf("\033[0;33mYou Lost !!");
		exit(1);
	}
	if (t->str[i][j - 1] == 'C')
	{
		t->str[i][j - 1] = 'P';
		t->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", t->moves);
		mlx_string_put(t->mlx_ptr, t->mlx_win, 15, 15, 0x0000000, "hello !!");
		t->moves++;
		return (0);
	}
	if (t->str[i][j - 1] == '1')
		return (0);
	return (1);
}

int	ft_exit(void *ptr)
{
	(void) *ptr;
	exit(1);
}

void	ft_move_left(t_map *t)
{
	int	i;
	int	j;

	i = -1;
	while (t->str[++i])
	{
		j = 0;
		while (t->str[i][j])
		{
			if (t->str[i][j] == 'P')
			{
				if (ft_move_left1(t, i, j) == 0)
					return ;
				if (t->str[i][j - 1] == 'E')
				{
					if (ft_check_collect(t) == 0)
					{
						ft_printf("\033[0;32m=== YOU WIN ===\n");
						exit(0);
					}
				}
			}
			j++;
		}
	}
}
