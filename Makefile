# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 21:39:24 by agusev            #+#    #+#              #
#    Updated: 2019/03/12 20:42:25 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =    ft_printf.c \
                src/
                src/
                src/
OFILES =    ft_printf.o \

INCLUDES = -I fT_printf.h
LIBFT_H = libft/libft.h
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
    make -C libft
    gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
    ar rc $(NAME) $(OFILES) ./libft/*.o
    ranlib $(NAME)

clean:
    make -C libft clean
    /bin/rm -f $(OFILES)

fclean: clean
    /bin/rm -f $(NAME)
    make -C libft fclean

re: fclean all