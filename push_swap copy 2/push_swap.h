/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:47:13 by skasmi            #+#    #+#             */
/*   Updated: 2022/05/24 22:42:59 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_int{
	int	l;
	int	p;
	int	k;
	int	j;
	int	i;
	int	pivot_3;
	int	pivot_2;
	int	p_pivot;
}	t_int;

typedef struct s_stack{
	int	*tab;
	int	size;
	int	used;
}	t_stack;

typedef struct s_table{
	t_stack	a;
	t_stack	b;
}	t_table;

void	print(char c, va_list cp, int *s);
int		ft_putchar(char c);
int		ft_hexa(unsigned long n, int s);
int		ft_unsigned_int(unsigned int n);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_printf(const char *format, ...);
int		ft_isdigit(int a);
int		ft_is_separator(char c, char cr);
int		ft_words(char *str, char c);
void	ft_write_word(char *dest, char *src, char c);
int		ft_write_split(char **split, char *str, char c);
char	**ft_split(char *s, char c);
void	ft_putstr_fd(char *s,	int fd);
int		ft_checknumbers(char **av);
void	ft_free_all(char **str);
int		ft_count(char **str, int k, int j);
void	ft_cont(char **num, int k, int j, int *sum);
int		*ft_double(char **av, int sum);
int		ft_atoi_custom(const	char	*str, char **num);
void	ft_error(char **num);
int		ft_check_sorted(t_table *m);
void	ft_sorting(t_table *m, int ac);
void	ft_two(t_table *m);
void	ft_three(t_table *m);
void	ft_four(t_table *m);
void	ft_five(t_table *m);
void	ft_six_ten(t_table *m);
void	ft_big_sort(t_table *m, int div);
int		ft_search_min(t_table *m);
int		ft_search_max(t_table *m);
int		ft_check_sorted_tab(int *tab, int size);
void	ft_big_sort2(t_table *m, t_int *var, int *tab);
int		*ft_copy(t_table *m);
void	ft_sort(int *tab, int size);
void	ft_send(t_table *m);
void	ft_free_stack(t_table *m);
void	ft_malloc(void *tab, int *hub, int *t, char **str);
void	sa(t_table *m, t_int var, int id);
void	sb(t_table *m, t_int var, int id);
void	ss(t_table *m, t_int var);
void	pa(t_table *m, t_int var);
void	pb(t_table *m, t_int var);
void	ra(t_table *m, t_int var, int id);
void	rb(t_table *m, t_int var, int id);
void	rr(t_table *m, t_int var);
void	rra(t_table *m, t_int var, int id);
void	rrb(t_table *m, t_int var, int id);
void	rrr(t_table *m, t_int var);

#endif