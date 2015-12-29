# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <bchaleil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 12:49:42 by bchaleil          #+#    #+#              #
#    Updated: 2015/12/18 15:59:20 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = main.c	ft_putchar.c	ft_putstr.c		ft_putstr_err.c		\
	  ft_print_tables.c		ft_strlen.c		ft_atoi.c				\
	  malloc_t_sqrt.c		nucleus.c		ft_char_in_str.c		\
	  get_file_info.c		ft_concat.c		low_gain.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS =

all: $(NAME)

$(NAME):
		@$(CC) -c $(CFLAGS) $(SRC)
		@$(CC) -o $(NAME) $(OBJ)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(OBJ)

re: fclean $(NAME)

test: fclean $(NAME)
		@cp bsq tests/bsq
		@cd tests && sh test.sh

 .PHONY: clean fclean
