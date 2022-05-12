/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:06:45 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/12 19:20:50 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_isdigit(int nb)
{
	if (nb <= '9' && nb >= '0')
	{
		return (1);
	}
	return (0);
}

long long	ft_atoi(const char *str)
{
	int	i;
	long long	m;
	int	w;

	w = 1;
	i = 0;
	m = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			w = w * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		m = (m * 10) + (str[i] - 48);
		i++;
	}
	return (m * w);
}

void	ft_check_maix_int(char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
	{
		printf("error !!\n");
		exit(0);
	}
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

void	*ft_memmove(void *str1, void *str2, size_t n)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)str1;
	s2 = (char *)str2;
	if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	if (s1 > s2)
	{
		while (i < (int)n)
		{
			s1[n - 1] = s2[n - 1];
			n--;
		}
	}
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	char	*ptr;

	// if (!s1 || !s2)
	// 	return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	ptr = (char *)malloc((i1 + i2) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s1, i1);
	ft_memmove(ptr + i1, s2, i2 + 1);
	ptr[i1 + i2] = 0;
	return (ptr);
}
