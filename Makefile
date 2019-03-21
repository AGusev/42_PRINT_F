# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 19:33:35 by agusev            #+#    #+#              #
#    Updated: 2019/03/21 14:48:58 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	ft_printf.c \
		srcs/adding_minus.c \
		srcs/adding_precision_string.c \
		srcs/adding_width_null_char.c \
		srcs/conversion_d_i.c \
		srcs/conversion_u_cap_d_cap_u.c \
		srcs/conversion_o_cap_o.c \
		srcs/conversion_x_cap_x.c \
		srcs/handle_width.c \
		srcs/adding_plus.c \
		srcs/adding_space.c \
		srcs/conversion_b.c \
		srcs/conversion_p.c \
		srcs/conversion_wide_c.c \
		srcs/conversions.c \
		srcs/handle_format.c \
		srcs/parse_flags.c \
		srcs/adding_precision_number.c \
		srcs/adding_width.c \
		srcs/conversion_c.c \
		srcs/conversion_s.c \
		srcs/conversion_wide_s.c \
		srcs/counters.c \
		srcs/handle_flags.c \
		srcs/handle_precision.c \
		srcs/conversion_float.c \
		srcs/ft_ftoa.c

OFILES =ft_printf.o \
		adding_minus.o \
		adding_precision_string.o \
		adding_width_null_char.o \
		conversion_d_i.o \
		conversion_u_cap_d_cap_u.o \
		conversion_o_cap_o.o \
		conversion_x_cap_x.o \
		handle_width.o \
		adding_plus.o \
		adding_space.o \
		conversion_b.o \
		conversion_p.o \
		conversion_wide_c.o \
		conversions.o \
		handle_format.o \
		parse_flags.o \
		adding_precision_number.o \
		adding_width.o \
		conversion_c.o \
		conversion_s.o \
		conversion_wide_s.o \
		counters.o \
		handle_flags.o \
		handle_precision.o \
		conversion_float.o \
		ft_ftoa.o

INCLUDES = -I ft_printf.h
LIBFT_H = libft/libft.h
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;36m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME):
	@echo "$(GREEN)GENERATING libft.a$(RESET)"
	make -C libft
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	@echo "$(GREEN)GENERATING OFILES$(RESET)"
	ar rc $(NAME) $(OFILES) ./libft/*.o
	ranlib $(NAME)
	@echo "$(GREEN)COMPILING libftprintf.a$(RESET)"
	@echo "$(BLUE)COMPLETED$(RESET)"

main:
	@echo "$(YELLOW)PRINTING TEST$(RESET)"
	@gcc $(FLAGS) $(NAME) $(INCLUDES) $(LIBFT) main.c

mclan :
	/bin/rm -f $(MAIN)
	@echo "$(RED)DELETING libftprintf.a$(RESET)"
	make -C libft fclean
	@echo "$(BLUE)COMPLETED$(RESET)"

clean:
	make -C libft clean
	/bin/rm -f $(OFILES)
	@echo "$(RED)DELETING objects libftprintf.a$(RESET)"
	@echo "$(BLUE)COMPLETED$(RESET)"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "$(RED)DELETING libftprintf.a$(RESET)"
	make -C libft fclean
	@echo "$(BLUE)COMPLETED$(RESET)"

re: fclean all