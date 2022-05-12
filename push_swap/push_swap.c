/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:42:13 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/12 19:23:06 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_espace(char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			j++;
		}
		i++;
	}
	if (i == j)
		return 1;
	return 0;
}

void ft_isnumber(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if(!(ft_isdigit(str[i][j])))
			{
				if (!((str[i][j] == '-' || str[i][j] == '+') && ft_isdigit(str[i][j + 1])))
				{
					printf("error !!\n");
					exit(1);
				}
			}
			j++;
		}
		ft_check_maix_int(str[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int i;
	char *join;
	char **splt;
	
	if (ac == 1)
		printf("error argument !!");
	i = 2;
	join = ft_strjoin(av[1], " ");
	while (i < ac)
	{
		if (ft_espace(av[i]))
		{
			printf("error !!\n");
			exit(1);
		}
		join = ft_strjoin(join, av[i]);
		join = ft_strjoin(join, " ");
		i++;
	}
	splt = ft_split(join, ' ');
	ft_isnumber(splt);
	i = 0;
	while (splt[i])
	{
		printf("%s\n", splt[i]);
		i++;
	}
	return (0);
}
