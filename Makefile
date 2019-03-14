# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 19:33:35 by agusev            #+#    #+#              #
#    Updated: 2019/03/14 15:01:32 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC=src/ft_putchar.c \
	src/ft_abs.c \
	src/ft_itoa_base.c \
	src/ft_strlen.c \
	src/counters.c \
	test_printf.c \
	src/ft_strnew.c \
	src/ft_strjoin.c \
	src/ft+printf1.c \
	src/ft_printf2.c
OBJ=*.o

INCL=./

$(NAME): $(SRC) src/test_printf.h
	@echo "\033[1;35mCompiling...$(NAME)\033[0m"
	gcc -Wall -Wextra -Werror -I $(INCL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[1;32m$(NAME) generated!\033[0m"

all: $(NAME)

clean:
	@echo "\033[1;31mCleaning...OBJ\033[0m"
	/bin/rm -f $(OBJ)

fclean: clean
	@echo "\033[1;31mCleaning...NAME\033[0m"
	/bin/rm -f $(NAME)

re: fclean all
	@echo "\033[1;31mCleaning...ALL\033[0m"
