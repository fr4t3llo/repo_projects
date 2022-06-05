/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:11:54 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/31 14:30:17 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_number(int number)
{
	if (number > 9)
		ft_write_number(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}
// void	ft_write_number(int number)
// {
// 	if (number > 9)
// 		ft_write_number(number / 10);
// 	write(1, &"123456789"[number % 10], 1);
// }

int main()
{
	int nb;
	
	nb = 1;
	while(nb <= 100)
	{
		if (nb % 5 == 0 && nb % 3 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else 
			ft_write_number(nb);
		write(1, "\n", 1);
		nb++;
	}
	return (0);
}