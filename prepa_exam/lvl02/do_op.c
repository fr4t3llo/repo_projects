/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:37:36 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/31 22:00:15 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i = 0;
	int a = 0;
	int b = 0;
	
	if (ac == 4)
	{
		if (av[2][0] != '/' && av[2][0] != '*' && av[2][0] != '-' && av[2][0] != '+')
			return (0);
		while (av[1][i])
		{
			if (av[1][i] > '9' && av[1][i] < '1')
				return (0);
			i++;
		}
		while (av[3][i])
		{
			if (av[3][i] > '9' && av[3][i] < '1')
				return (0);
			i++;
		}
		a = atoi(av[1]);
		b = atoi(av[3]);
		
		if (av[2][0] == '/')
			printf("%d", a / b);
		else if (av[2][0] == '*')
			printf("%d", a * b);
		else if (av[2][0] == '-')
			printf("%d", a - b);
		else
			printf("%d", a + b);
	}
	printf("\n");
	return(0);
}