# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 23:14:05 by aadamik           #+#    #+#              #
#    Updated: 2023/12/06 01:30:36 by aadamik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printf_write.c ft_printf_main.c

OBJS = $(SRCS:.c=.o)

LIBDIR = libft
LIBFT = libft.a

NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	mv $(LIBDIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I./libft -c $< -o $@

$(LIBFT):
	make -C libft all

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean $(NAME)

.PHONY: all clean fclean re 