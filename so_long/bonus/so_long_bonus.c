/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:24:49 by skasmi            #+#    #+#             */
/*   Updated: 2022/04/23 07:44:35 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	animate_coins(t_map *t)
{
	if (t->counter <= 5)
		t->collect = mlx_xpm_file_to_image(t->mlx_ptr,
				"./xpmfile/coin.xpm", &t->width, &t->height);
	else if (t->counter <= 10)
		t->collect = mlx_xpm_file_to_image(t->mlx_ptr,
				"./xpmfile/coin1.xpm", &t->width, &t->height);
	else if (t->counter <= 15)
		t->collect = mlx_xpm_file_to_image(t->mlx_ptr,
				"./xpmfile/coin2.xpm", &t->width, &t->height);
	else if (t->counter <= 20)
		t->collect = mlx_xpm_file_to_image(t->mlx_ptr,
				"./xpmfile/coin3.xpm", &t->width, &t->height);
	else if (t->counter <= 25)
		t->collect = mlx_xpm_file_to_image(t->mlx_ptr,
				"./xpmfile/coin4.xpm", &t->width, &t->height);
	else if (t->counter > 26)
		t->counter = 0;
	t->counter++;
	draw_map(t);
	return (0);
}
void steps(t_map *t)
{
	char *str;
	
	str = ft_itoa(t->moves);
	mlx_string_put(t->mlx_ptr, t->mlx_win, 20, 20, 0x000FFF, str);
	printf("heyy bro \n");
	free(str);
}

int	main(int ac, char **av)
{
	t_map	t;

	t.i = 0;
	t.moves = 1;
	if (ac != 2)
	{
		ft_printf("eroor argument !!");
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
	ft_draw_map(&t);
	steps(&t);
	mlx_key_hook(t.mlx_win, ft_move, &t);
	mlx_hook(t.mlx_win, 17, 0, ft_close, &t);
	t.counter = 0;
	mlx_loop_hook(t.mlx_ptr, animate_coins, &t);
	mlx_loop(t.mlx_ptr);
	return (0);
}
