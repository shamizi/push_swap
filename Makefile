# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 15:07:55 by shamizi           #+#    #+#              #
#    Updated: 2021/11/05 15:57:41 by shamizi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =push_swap

SRCS= main.c \
	  push.c \
	  reverse_rotate.c \
	  rotate.c \
	  sort.c \
	  sort_utils.c \
	  swap.c \
	  utils.c \
	  sort_plus.c \
	  ft_split.c \
	  initfree.c

OBJS =$(SRCS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
clean: 
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

