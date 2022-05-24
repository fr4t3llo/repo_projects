/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:43:25 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/22 23:44:30 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i1;
	int		i2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	ptr = (char *)malloc((i1 + i2) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s1, i1);
	ft_memmove(ptr + i1, s2, i2 + 1);
	ptr[i1 + i2] = 0;
	free(s1);
	return (ptr);
}

void	ft_check_maix_int(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
	{
		ft_printf("error !!\n");
		exit(0);
	}
}
