# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 17:15:13 by pschmunk          #+#    #+#              #
#    Updated: 2024/08/31 19:50:05 by pschmunk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RFLAG = -lreadline
RM = rm -rf

MINISHELL = minishell

MINISHELL_SRC =	./sources/minishell.c				\
				./sources/executor/echo.c			\
				./sources/executor/export.c			\
				./sources/executor/pwd.c			\
				./sources/executor/unset.c			\
				./sources/executor/simple_exec.c	\
				./sources/executor/piping.c			\
				./sources/parser/env.c				\
				./sources/parser/parser.c			\
				./sources/parser/custom_split.c		\
				./sources/parser/tokenizer.c		\
				./sources/parser/heredoc.c			\
				./sources/parser/list_new.c			\
				./sources/parser/list_add.c			\
				./sources/signals/signal_handling.c	\
				./sources/utils/debug.c				\
				./sources/utils/utils.c				\

MINISHELL_OBJ = $(MINISHELL_SRC:.c=.o)

LIBFTPRINTF = ./includes/printf/libftprintf.a
LIBFTPRINTF_DIR = ./includes/printf

all: $(MINISHELL)

$(MINISHELL): $(MINISHELL_OBJ) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(MINISHELL_OBJ) $(LIBFTPRINTF) -o minishell $(RFLAG)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

clean:
	$(RM) $(MINISHELL_OBJ)
	make -C $(LIBFTPRINTF_DIR) clean
fclean: clean
	$(RM) $(MINISHELL)
	make -C $(LIBFTPRINTF_DIR) fclean
re: fclean all

.PHONY:	all clean fclean re 