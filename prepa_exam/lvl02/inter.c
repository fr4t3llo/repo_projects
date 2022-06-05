/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:14:57 by skasmi            #+#    #+#             */
/*   Updated: 2022/06/01 19:04:20 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// int check_double(char c, char *str)
// {
	
// }
int main(int ac, char **av)
{
	int i;
	int j;
	int k;
	int cp;
	
	cp = 0;
	k = 0;
	i = 0;
	j = 0;
	if (ac == 3)
	{
		while(av[1][i] != '\0')
		{
			if (av[1][i] != av[2][j])
				j++;
			else
				{
					cp++;
					while (av[1][i] == av[1][k] && av[1][i] != '\0' && cp == 1)
						{
							
							k++;
						}
				write(av[2][j])
				}
		}
	}
}