# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 19:33:35 by agusev            #+#    #+#              #
#    Updated: 2019/03/13 21:08:06 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test_printf.a

SRC=src/ft_putchar.c src/ft_abs.c src/ft_itoa_base.c src/ft_strlen.c src/counters.c test_printf.c
OBJ=*.o

INCL=./

$(NAME): $(SRC) src/test_printf.h
	@echo "\033[1;35mCompiling...\033[0m"
	gcc -Wall -Wextra -Werror -I $(INCL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[1;32m$(NAME) generated!\033[0m"

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)
		@echo "\033[0;31mCleaning...\033[0m"

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
	@echo "\033[0;31mCleaning all...\033[0m"