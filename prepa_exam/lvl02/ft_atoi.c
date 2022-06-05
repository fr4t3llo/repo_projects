/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:01:55 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/31 22:38:24 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// int ft_atoi(const char *str)
// {
// 	int i;
// 	int result;
	
// 	int n = 1;	
// 	result = 0;
// 	i = 0;
	
// 	while (str[i] <= 32)
// 		i++;
// 	if (str[i] == '-')
// 	{
// 		n = -1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 		i++;
// 	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
// 	{
// 		result *= 10;
// 		result += str[i] - '0';
// 		i++;
// 	printf("test");
// 	}
// 	return (result * n);
// }
int		ft_atoi(const char *str)
{
	int i;
	int n;
	int result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * n);
}
int main()
{
	char *str;
	int s;
	s =  ft_atoi(str);
	printf("%d", s);
	return(0);
}