# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 19:33:35 by agusev            #+#    #+#              #
#    Updated: 2019/03/13 19:36:01 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = testprintf.a
CFLAGS = -Wall -Werror -Wextra
HEADER = test_printf.h

CFILES = test_printf.c counters.c
OFILES = *.o

all: $(NAME)

$(NAME):
    gcc $(CFLAGS) -I$(HEADER) -c $(CFILES)
    ar rc $(NAME) $(OFILES)
    ranlib $(NAME)

clean:
    /bin/rm -f $(OFILES)

fclean: clean
    /bin/rm -f $(NAME)

re: fclean all