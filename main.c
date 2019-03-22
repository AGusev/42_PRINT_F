/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:35:40 by agusev            #+#    #+#             */
/*   Updated: 2019/03/21 23:50:34 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{

// number of char

	int		a;
	int		b;

	a = ft_printf("\033[1;33m\n\nChecking flags ft_printf:\033[0m\n\n%%.5s = %.5s\n%%c = %c\n%%#o = %#o\n%%u = %u\n%%-+5d = %-+5d\n%%10.4f = %10.4f\n%%0x = %0x\n%%#o = %#o\n", "asdefg", 'a', 12345, -123, 41245, 412415.8247223, 1214, -1);
	b = printf("\033[1;33m\n\nChecking flags printf:\033[0m\n\n%%.5s = %.5s\n%%c = %c\n%%#o = %#o\n%%u = %u\n%%-+5d = %-+5d\n%%10.4f = %10.4f\n%%0x = %0x\n%%#o = %#o\n\n", "asdefg", 'a', 12345, -123, 41245, 412415.8247223, 1214, -1);
	//printf("ft = %d, reg = %d\n", a, b);
	printf("\n");

	// other

	ft_printf("\033[1;33mPrinting percent sign =\n\n\033[0m %%\n\n");

	// %d

	printf("\033[1;33mFlag d  \033[0m \n\n");

	ft_printf("flag d = %d\n", 123);
	ft_printf("flag d = %d\n", -123);
	ft_printf("flag d = %d\n", -2147483648);
	ft_printf("flag d = %d\n", 2147483647);

	printf("\np flag d = %d\n", 123);
	printf("p flag d = %d\n", -123);
//	printf("p flag d = %d\n", -2147483648);
	printf("p flag d = %d\n", 2147483647);

	printf("\n");

	// %c

	printf("\033[1;33mFlag c  \033[0m \n\n");

	ft_printf("flag c = %c\n", 'a');
	ft_printf("flag c = %c\n", 0);
	ft_printf("flag c = %c\n", '0');
	ft_printf("flag c = %c\n", 127);

	printf("\np flag c = %c\n", 'a');
	printf("p flag c = %c\n", 0);
	printf("p flag c = %c\n", '0');
	printf("p flag c = %c\n", 127);

	printf("\n");

	// %i

	printf("\033[1;33mFlag i  \033[0m \n\n");

	ft_printf("flag i = %i\n", 123);
	ft_printf("flag i = %i\n", -123);
	ft_printf("flag i = %i\n", -2147483648);
	ft_printf("flag i = %i\n", 2147483647);

	printf("\np flag i = %i\n", 123);
	printf("p flag i = %i\n", -123);
//	printf("p flag i = %i\n", -2147483648);
	printf("p flag i = %i\n", 2147483647);

	printf("\n\n");

	// failures

	printf("\033[1;31mFILECHECKER FAILED TESTS\033[0m\n\n\n");
	ft_printf("ft_printffailure #0045 = %#-08x\n", 42);
//	printf("printffailure #0045 = %#-08x\n", 42);

	ft_printf("ft_printffailure #0089 = %-05o\n", 2500);
//	printf("printffailure #0089 = %-05o\n", 2500);

	ft_printf("ft_printffailure #0134 = %-05d\n", 42);
//	printf("printffailure #0134 = %-05d\n", 42);

	ft_printf("ft_printffailure #0136 = %-05d\n", -42);
//	printf("printffailure #0136 = %-05d\n", -42);

//	ft_printf("ft_printffailure # 150 %lld\n", -9223372036854775808);
//	printf("printffailure # 150 %lld\n", -9223372036854775808);

//	ft_printf("ft_printffailure # 152 %jd\n", -9223372036854775808);
//	printf("printffailure # 150 %lld\n", -9223372036854775808);

	ft_printf("ft_printffailure #0195 = %hU\n", 42);
//	printf("printffailure #0195 = %hU\n", 42);

	ft_printf("ft_printffailure #0196 = %U\n", 4294967296);
//	printf("printffailure #0196 = %U\n", 4294967296);

	ft_printf("\n\n\n\033[1;35mFlag f\033[0m\n\n\n\n");

	ft_printf("\033[0;33mft_printf#1 : \033[0m  %f\n", 93847587871.123);
	printf("\033[0;32mprintf#1 : \033[0m%f\n", 93847587871.123);
	ft_printf("\033[0;33mft_printf#2 : \033[0m%20f\n", 93847587871.123);
	printf("\033[0;32mprintf#2 : \033[0m%20f\n", 93847587871.123);
	ft_printf("\033[0;33mft_printf#3 : \033[0m%.2f\n", 93847587871.123);
	printf("\033[0;32mprintf#3 : \033[0m%.2f\n", 93847587871.123);
	ft_printf("\033[0;33mft_printf#4 : \033[0m  %-20f\n", 93847587871.123);
	printf("\033[0;32mprintf#4 : \033[0m  %-20f\n", 93847587871.123);
	ft_printf("\033[0;33mft_printf#5 : \033[0m  %020.2f\n", 93847587871.123);
	printf("\033[0;32mprintf#5 : \033[0m  %020.2f\n", 93847587871.123);
	ft_printf("\033[0;33mft_printf#6 : \033[0m  %#20.2f\n", 93847587871.123);
	printf("\033[0;32mprintf#6 : \033[0m  %#20.2f\n", 93847587871.123);
	ft_printf("\033[0;33mft_printf#7 : \033[0m  %+20.2f\n", 93847587871.123);
	printf("\033[0;32mprintf#7 : \033[0m  %+20.2f\n", 93847587871.123);
	ft_printf("\033[0;33mft_printf#8 : \033[0m  % 20.2f\n", 93847587871.123);
	printf("\033[0;32mprintf#8 : \033[0m  % 20.2f\n", 93847587871.123);


	printf("\n\n\n\033[1;35m-> Bonus Part - flag b\033[0m\n\n\n\n");
	ft_printf("%b\n",44);
	ft_printf("%b\n",128);
	ft_printf("%b\n",64);
	ft_printf("%b\n",32);
	ft_printf("%b\n",16);
	ft_printf("%b\n",8);
	ft_printf("%b\n",4);
	ft_printf("%b\n",2);
	ft_printf("%b",1);
	printf("\033[0m\n\n\n\n");

	return (0);
}
