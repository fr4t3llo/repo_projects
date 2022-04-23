/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_and_free_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:09:17 by skasmi            #+#    #+#             */
/*   Updated: 2022/04/23 06:23:14 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_map *t)
{
	int	i;

	i = 0;
	while (t->str[i])
	{
		free(t->str[i]);
		i++;
	}
	free(t->str);
}

int	ft_close(t_map *t)
{
	ft_free(t);
	ft_printf("=== GAME END ===\n");
	exit(0);
	return (0);
}

int	ft_move(int keycode, t_map *t)
{
	if (keycode == 53)
		ft_close(t);
	else if (keycode == 13)
		ft_move_up(t);
	else if (keycode == 1)
		ft_move_down(t);
	else if (keycode == 0)
		ft_move_left(t);
	else if (keycode == 2)
		ft_move_right(t);
	return (0);
}
