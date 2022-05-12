/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:47:13 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/12 19:18:27 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	print(char c, va_list cp, int *s);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_unsigned_int(unsigned int n);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_hexa(unsigned long n, int s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_is_separator(char c, char cr);
int		ft_words(char *str, char c);
void	ft_write_word(char *dest, char *src, char c);
int		ft_write_split(char **split, char *str, char c);
char	**ft_split(char *s, char c);
void	*ft_memmove(void *str1, void *str2, size_t n);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_isdigit(int nb);
long long	ft_atoi(const char *str);
void	ft_check_maix_int(char *str);

typedef struct s_stack
{	
	int size;
	int used_size;
	int *array;
}		t_stack;

typedef struct s_sort
{
	t_stack stack_a;
	t_stack stack_b;
}			t_sort;
 #endif