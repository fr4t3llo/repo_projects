# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 12:49:26 by skasmi            #+#    #+#              #
#    Updated: 2022/05/10 18:20:42 by skasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

NAME = push_swap

src = push_swap.c ft_printf.c ft_printf_utils.c push_swap_utils.c ft_split.c\

obj = $(src:%.c=%.o)

$(NAME) : $(obj)
		CC $(CFLAGS) $(obj) -o $(NAME)
		
all: $(NAME)

clean : 
		rm -f $(obj)

fclean: clean
		rm -f $(NAME)

re: fclean all