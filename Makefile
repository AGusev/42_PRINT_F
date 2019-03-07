# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 21:39:24 by agusev            #+#    #+#              #
#    Updated: 2019/03/07 13:24:37 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=
SRC=

OBJ=

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