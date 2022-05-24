/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:42:13 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 22:39:28 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_malloc(void *tab, int *hub, int *t, char **str)
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

// int	ft_espace(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ' ')
// 		{
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (i == j)
// 		return (1);
// 	return (0);
// }

// char	*ft_join(char **av, int ac)
// {
// 	int		i;
// 	char	*join;
	
// 	i = 2;
// 	join = ft_strjoin(av[1], " ");
// 	while (i < ac)
// 	{
// 		if (ft_espace(av[i]))
// 		{
// 			ft_printf("error !!\n");
// 			exit(1);
// 		}
// 		join = ft_strjoin_free(join, av[i]);
// 		join = ft_strjoin_free(join, " ");
// 		i++;
// 	}
// 	return (join);
// }


int	main(int ac, char **av)
{
	t_table	m;

	if (ac == 1)
		return (0);
	m.a.size = ft_checknumbers(av);
	m.a.tab = ft_double(av, m.a.size);
	m.a.used = m.a.size;
	if (ft_check_sorted(&m) == 1)
		return (free(m.a.tab), 0);
	m.b.size = m.a.size;
	m.b.tab = (int *)malloc(m.b.size * sizeof(int));
	ft_malloc(m.b.tab, m.a.tab, NULL, NULL);
	m.b.used = 0;
	ft_sorting(&m, m.a.size);
	return (0);
}
