/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:24:49 by skasmi            #+#    #+#             */
/*   Updated: 2022/04/18 06:04:25 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_collect(t_map *t)
{
	int	i;
	int	j;

	i = 0;
	while (t->str[i])
	{
		j = 0;
		while (t->str[i][j])
		{
			if (t->str[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_read_so_long(t_map *t, char **av)
{
	t->fd = open(av[1], O_RDONLY);
	if (t->fd < 0)
	{
		ft_printf("\033[0;31mfile not found !!");
		exit(1);
	}
	t->tab = get_next_line(t->fd);
	while (t->tab)
	{
		free(t->tab);
		t->tab = get_next_line(t->fd);
		t->i++;
	}
	t->str = (char **)malloc((t->i + 1) * sizeof(char *));
	t->j = 0;
	close(t->fd);
	t->fd = open(av[1], O_RDONLY);
	t->str[t->j] = get_next_line(t->fd);
	while (t->j < t->i)
	{
		t->j++;
		t->str[t->j] = get_next_line(t->fd);
	}
	t->str[t->j] = NULL;
}

int	ft_arg(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 1] == 'r' && av[1][i - 2] == 'e'
		&& av[1][i - 3] == 'b' && av[1][i - 4] == '.')
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_map	t;

	t.i = 0;
	t.moves = 1;
	if (ac != 2)
	{
		printf("eroor argument !!");
		exit(1);
	}
	if (ft_arg(av) == 0)
	{
		ft_printf("\033[0;31mextention of map must finished -> .ber !!\n");
		exit(1);
	}
	ft_read_so_long(&t, av);
	check_content(&t);
	check_walls(t.str);
	// ft_check_collect()
	ft_draw_map(&t);
	mlx_key_hook(t.mlx_win, ft_move, &t);
	mlx_hook(t.mlx_win, 17, 0, ft_close, &t);
	mlx_loop(t.mlx_ptr);
	return (0);
}
