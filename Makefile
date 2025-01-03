# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 17:55:25 by xhuang            #+#    #+#              #
#    Updated: 2024/12/21 19:26:18 by xhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

INCLUDE = -I.

SRCS = sort_lib/push.c sort_lib/rev_rotate.c sort_lib/rotate.c sort_lib/swap.c \
		free.c sort_array.c sort_stack.c sort_utils.c stack_initi.c\
		main.c

SRCOBJ := $(SRCS:%.c=%.o) 


.PHONY: all clean fclean re libft

all:	libft $(NAME)

libft: 
	@make -C libft/

$(NAME):	$(SRCOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCOBJ) -Llibft -lft -o $(NAME)
	@echo "Executable $(NAME) has been created."


%.o:	%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

clean:	
	$(RM) $(SRCOBJ) 
	@make clean -C libft
	@echo "Object files have been deleted."

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@echo "Library has been deleted."

re: fclean all 
