/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:48:03 by skasmi            #+#    #+#             */
/*   Updated: 2022/04/23 07:41:54 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	calc_size(long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*sep_num(char *str,	int n,	int size)
{
	int	i;
	int	a;

	i = 0;
	a = n;
	if (n < 0)
		n = n * -1;
	str[size] = '\0';
	while (size-- != 0)
	{
		str[size] = n % 10 + 48;
		if (a < 0)
			str[i] = '-';
		n = n / 10;
	}
	return (str);
}
char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s1[n])
		n++;
	p = (char *)malloc(sizeof(char) * (n + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*tab;

	i = 0;
	tab = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	if (n > 0)
	{
		i = calc_size(n);
		tab = (char *)malloc(i + 1);
	}
	else if (n < 0)
	{
		i = calc_size(n * -1);
		tab = (char *)malloc(i + 2);
		i = i + 1;
	}
	if (tab == NULL)
		return (NULL);
	tab = sep_num(tab, n, i);
	return (tab);
}
