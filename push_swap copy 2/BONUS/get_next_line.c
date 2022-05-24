/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:55:18 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 21:56:08 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strjoin_custom(char const *s1,	char const *s2)
{
	char	*tab;
	size_t	i;
	size_t	j;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = i + j;
	tab = (char *)malloc(k + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		tab[i] = (char)s1[i];
		i++;
	}
	while (s2[j] != '\0')
		tab[i++] = (char)s2[j++];
	tab[k] = '\0';
	free((char *)s1);
	return (tab);
}

static int	get_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	free_all(char **str)
{
	free (*str);
	*str = NULL;
}

static char	*fill_line(char **rem,	int a)
{
	char	*line;
	char	*tmp;
	int		index;

	tmp = NULL;
	index = get_line(*rem);
	if (a == 0 && *(*rem) == '\0')
		return (free_all(rem), NULL);
	else if ((*rem)[index] == '\n')
	{
		line = (char *)malloc(sizeof(char) * (index + 2));
		if (line == NULL)
			return (free_all(&line), NULL);
		ft_memcpy(line, *rem, index);
		line[index] = '\n';
		line[index + 1] = '\0';
		tmp = ft_strdup(*rem + index + 1);
		free_all(rem);
		*rem = tmp;
		return (line);
	}
	line = ft_strdup(*rem);
	free_all(rem);
	return (line);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*buff;
	static char	*rem = NULL;

	i = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (free_all(&buff), NULL);
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free_all(&buff), NULL);
		buff[i] = '\0';
		if (!rem)
			rem = ft_strdup(buff);
		else
			rem = ft_strjoin_custom(rem, buff);
		if (get_line(rem) != -1)
			break ;
	}
	return (free_all(&buff), fill_line(&rem, i));
}
