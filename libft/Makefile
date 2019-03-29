# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 01:37:17 by agusev            #+#    #+#              #
#    Updated: 2019/03/29 01:37:19 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = 	./ft_helper_1.c \
		./ft_itoa_base.c \
		./ft_itoa_base_unsigned.c \
		./ft_itoa_intmax.c \
		./ft_memcpy.c \
		./ft_strccrt.c \
		./ft_strchr.c \
		./ft_strdel.c \
		./ft_strdup.c \
		./ft_strjoin.c \
		./ft_strlen.c \
		./ft_strnew.c \
		./ft_strtoupper.c \
		./ft_update.c \
		./ft_wstrdup.c \
		./ft_wstrlen.c \
		./ft_strcmp.c \
		./ft_itoa_unsigned.c \
		./ft_strcpy.c \
		./ft_strsub.c

OBJ =   ./ft_helper_1.o \
		./ft_itoa_base.o \
		./ft_itoa_base_unsigned.o \
		./ft_itoa_intmax.o \
		./ft_memcpy.o \
		./ft_strccrt.o \
		./ft_strchr.o \
		./ft_strdel.o \
		./ft_strdup.o \
		./ft_strjoin.o \
		./ft_strlen.o \
		./ft_strnew.o \
		./ft_strtoupper.o \
		./ft_update.o \
		./ft_wstrdup.o \
		./ft_wstrlen.o \
		./ft_strcmp.o \
		./ft_itoa_unsigned.o \
		./ft_strcpy.o \
		./ft_strsub.o

INCL=./

$(NAME): $(SRC) libft.h
	gcc -Wall -Wextra -Werror -I $(INCL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
