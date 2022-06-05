/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:55:47 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/31 17:26:52 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int j = 0;
	char c;

	j = ft_strlen(av[1]) - 1;
	(void)ac;

	while (j >= 0)
	{
		c = av[1][j];
		write (1, &c, 1);
		j--;
	}
	write (1, "\n", 1);
	return (0);
}
