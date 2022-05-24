# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 12:49:26 by skasmi            #+#    #+#              #
#    Updated: 2022/05/24 22:49:13 by skasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror 

NAME=push_swap

SRCS=push_swap.c\
		check_numbers.c\
		ft_double.c\
		move.c\
		check_sorted.c\
		move2.c\
		move3.c\
		ft_sorting.c\
		ft_sorting2.c\
		ft_big_sort.c\
		ft_printf_utils.c\
		ft_printf.c\
		ft_putstr_fd.c\
		ft_split.c\

BSRCS=	push_swap_bonus.c\
		ft_check_numbers_bonus.c\
		ft_double_bonus.c\
		ft_check_sorted_bonus.c\
		ft_move_bonus.c\
		ft_move2_bonus.c\
		ft_move3_bonus.c\
		get_next_line.c\
		
BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS)
		CC $(CFLAGS)  $(OBJCTS) -o $(NAME)

all: $(NAME)

bonus : $(BOBJCTS)
		CC $(CFLAGS)  $(BOBJCTS) -o push_swap_bonus

clean:
		rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
		rm -f $(NAME) push_swap_bonus
		
re: fclean all	

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror 

# NAME = push_swap

# src = 	push_swap.c ft_sortingg.c ft_printf.c ft_sorting2.c ft_printf_utils.c push_swap_utils.c ft_split.c \
# 		move.c move2.c move3.c  check_sorted.c \
# 		ft_putstr_fd.c ft_big_sort.c ft_complete.c check_numbers.c \

# obj = $(src:%.c=%.o)

# $(NAME) : $(obj)
# 		CC $(CFLAGS) $(obj) -o $(NAME)
		
# all: $(NAME)

# clean : 
# 		rm -f $(obj)

# fclean: clean
# 		rm -f $(NAME)

# re: fclean all