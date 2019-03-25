/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:35:40 by agusev            #+#    #+#             */
/*   Updated: 2019/03/24 21:03:57 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{


// number of char

	int		a;
	int		b;
	int		c;

	a = ft_printf("\033[1;33m\n\nChecking flags ft_printf:\033[0m\n\n%%.5s = %.5s\n%%c = %c\n%%#o = %#o\n%%u = %u\n%%-+5d = %-+5d\n%%10.4f = %10.4f\n%%0x = %0x\n%%#o = %#o\n", "asdefg", 'a', 12345, -123, 41245, 412415.8247223, 1214, -1);
	b = printf("\033[1;33m\n\nChecking flags printf:\033[0m\n\n%%.5s = %.5s\n%%c = %c\n%%#o = %#o\n%%u = %u\n%%-+5d = %-+5d\n%%10.4f = %10.4f\n%%0x = %0x\n%%#o = %#o\n\n", "asdefg", 'a', 12345, -123, 41245, 412415.8247223, 1214, -1);
	c = printf("\033[1;33m\n\nChecking flags X:\033[0m\n\n%%.5s = %.5s\n%%c = %c\n%%#o = %#o\n%%u = %u\n%%-+5d = %-+5d\n%%10.4f = %10.4f\n%%0X = %0X\n%%#o = %#o\n\n", "asdefg", 'a', 12345, -123, 41245, 412415.8247223, 1214, -1);
	//printf("ft = %d, reg = %d\n", a, b);
	printf("\n");

	// other

	ft_printf("\033[1;33mPrinting percent sign =\n\n\033[0m %%\n\n");

	// %d

	printf("\033[1;33mFlag d  \033[0m \n\n");

	ft_printf("ft_printf %d\n", 123) == printf("printf    %d\n", 123) ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %d\n", -123) == printf("printf    %d\n", -123) ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %d\n", -2147483647) == printf("printf    %d\n", -2147483647) ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %d\n", 2147483647) == printf("printf    %d\n", 2147483647) ? write(1, "\n", 1) : write(1, "\n", 1);

	ft_printf("ft_print_f %d\n", -2147483648);


//	printf("p flag d = %d\n", -2147483648);


	printf("\n");

	// %c

	printf("\033[1;33mFlag c  \033[0m \n\n");

	ft_printf("ft_printf %c\n", 'a') == printf("printf    %c\n", 'a') ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %c\n", 0) == printf("printf    %c\n", 0) ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %c\n", '0') == printf("printf    %c\n", '0') ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %c\n", 127) == printf("printf    %c\n", 127) ? write(1, "\n", 1) : write(1, "\n", 1);


	printf("\n");

	// %i

	printf("\033[1;33mFlag i  \033[0m \n\n");

	ft_printf("ft_printf %i\n", 123) == printf("printf    %i\n", 123) ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %i\n", -123) == printf("printf    %i\n", -123) ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %i\n", -2147483647) == printf("printf    %i\n", -2147483647) ? write(1, "\n", 1) : write(1, "\n", 1);
	ft_printf("ft_printf %i\n", 2147483647) == printf("printf    %i\n", 2147483647) ? write(1, "\n", 1) : write(1, "\n", 1);

	ft_printf("ft_printf %i\n", -2147483648);

	printf("\n");

	// failures


	printf("\033[1;31mFILECHECKER FAILED TESTS\033[0m\n\n\n");

	ft_printf("ft_printffailure #0195 = %hU\n", 42);
//	printf("printffailure #0195 = %hU\n", 42);

	ft_printf("ft_printffailure #0196 = %U\n", 4294967296);
//	printf("printffailure #0196 = %U\n", 4294967296);






	ft_printf("\n\n\n\033[1;35mFlag f\033[0m\n\n\n\n");


	printf("\n");
	ft_printf("ft_printf %f\n", 93847587871.123);
	printf("printf    %f\n", 93847587871.123);
	printf("\n");


	ft_printf("ft_printf %20f\n", 93847587871.123);
	printf("printf    %20f\n", 93847587871.123);
	printf("\n");


	ft_printf("ft_printf %.2f\n", 93847587871.123);
	printf("printf    %.2f\n", 93847587871.123);
	printf("\n");

	ft_printf("ft_printf %-20f\n", 93847587871.123);
	printf("printf    %-20f\n", 93847587871.123);
	printf("\n");


	ft_printf("ft_printf %020.2f\n", 93847587871.123);
	printf("printf    %020.2f\n", 93847587871.123);
	printf("\n");


	ft_printf("ft_printf %#20.2f\n", 93847587871.123);
	printf("printf    %#20.2f\n", 93847587871.123);

	printf("\n");

	ft_printf("ft_printf %+20.2f\n", 93847587871.123);
	printf("printf    %+20.2f\n", 93847587871.123);
	printf("\n");


	ft_printf("ft_printf % 20.2f\n", 93847587871.123);
	printf("printf    % 20.2f\n", 93847587871.123);
	printf("\n");





	printf("\n\n\n\033[1;35m-> Bonus Part - flag b\033[0m\n\n\n\n");
	ft_printf("44   %b\n",44);
	ft_printf("128  %b\n",128);
	ft_printf("64   %b\n",64);
	ft_printf("32   %b\n",32);
	ft_printf("16   %b\n",16);
	ft_printf("8    %b\n",8);
	ft_printf("4    %b\n",4);
	ft_printf("2    %b\n",2);
	ft_printf("1    %b",1);
	printf("\033[0m\n\n\n\n");


	return (0);
}
