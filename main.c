/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:35:40 by agusev            #+#    #+#             */
/*   Updated: 2019/03/19 18:38:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{

// number of char

	int		a;
	int		b;

	a = ft_printf("Checking flags ft_printf:\n%%.5s = %.5s\n%%c = %c\n%%#o = %#o\n%%u = %u\n%%-+5d = %-+5d\n%%10.4f = %10.4f\n%%0x = %0x\n%%#o = %#o\n\n", "asdefg", 'a', 12345, -123, 41245, 412415.8247223, 1214, -1);
	b = printf("Checking flags printf:\n%%.5s = %.5s\n%%c = %c\n%%#o = %#o\n%%u = %u\n%%-+5d = %-+5d\n%%10.4f = %10.4f\n%%0x = %0x\n%%#o = %#o\n\n", "asdefg", 'a', 12345, -123, 41245, 412415.8247223, 1214, -1);
	printf("ft = %d, reg = %d\n", a, b);
	printf("\n");

	// other

	ft_printf("percent sign = %%\n");

	// %d

	ft_printf("flag d = %d\n", 123);
	ft_printf("flag d = %d\n", -123);
	ft_printf("flag d = %d\n", -2147483648);
	ft_printf("flag d = %d\n", 2147483647);

	// %c
	
	ft_printf("flag c = %c\n", 'a');
	ft_printf("flag c = %c\n", 0);
	ft_printf("flag c = %c\n", '0');
	ft_printf("flag c = %c\n", 127);

	// %i

	ft_printf("flag i = %i\n", 123);
	ft_printf("flag i = %i\n", -123);
	ft_printf("flag i = %i\n", -2147483648);
	ft_printf("flag i = %i\n\n", 2147483647);

	// failures

	printf("FILECHECKER FAILED TESTS\n");
	ft_printf("f - failure #0045 = %#-08x\n", 42);
//	printf("p - failure #0045 = %#-08x\n", 42);

	ft_printf("f - failure #0089 = %-05o\n", 2500);
//	printf("p - failure #0089 = %-05o\n", 2500);

	ft_printf("f - failure #0134 = %-05d\n", 42);
//	printf("p - failure #0134 = %-05d\n", 42);

	ft_printf("f - failure #0136 = %-05d\n", -42);
//	printf("p - failure #0136 = %-05d\n", -42);

//	ft_printf("f - failure # 150 %lld\n", -9223372036854775808);
//	printf("p - failure # 150 %lld\n", -9223372036854775808);

//	ft_printf("f - failure # 152 %jd\n", -9223372036854775808);
//	printf("p - failure # 150 %lld\n", -9223372036854775808);

	ft_printf("f - failure #0195 = %hU\n", 42);
//	printf("p - failure #0195 = %hU\n", 42);

	ft_printf("f - failure #0196 = %U\n", 4294967296);
//	printf("p - failure #0196 = %U\n", 4294967296);

	ft_printf("f - float #1 - %f\n", 93847587871.123);
	printf("p - float #1 - %f\n", 93847587871.123);
	ft_printf("f - float #2 - %20f\n", 93847587871.123);
	printf("p - float #2 - %20f\n", 93847587871.123);
	ft_printf("f - float #3 - %.2f\n", 93847587871.123);
	printf("p - float #3 - %.2f\n", 93847587871.123);
	ft_printf("f - float #4 - %-20f\n", 93847587871.123);
	printf("p - float #4 - %-20f\n", 93847587871.123);
	ft_printf("f - float #5 - %020.2f\n", 93847587871.123);
	printf("p - float #5 - %020.2f\n", 93847587871.123);
	ft_printf("f - float #6 - %#20.2f\n", 93847587871.123);
	printf("p - float #6 - %#20.2f\n", 93847587871.123);
	ft_printf("f - float #7 - %+20.2f\n", 93847587871.123);
	printf("p - float #7 - %+20.2f\n", 93847587871.123);
	ft_printf("f - float #8 - % 20.2f\n", 93847587871.123);
	printf("p - float #8 - % 20.2f\n\n", 93847587871.123);
	
	printf("BONUS PART FLAG b\n\n");
	ft_printf("%b\n",44);
	ft_printf("%b\n",128);
	ft_printf("%b\n",64);
	ft_printf("%b\n",32);
	ft_printf("%b\n",16);
	ft_printf("%b\n",8);
	ft_printf("%b\n",4);
	ft_printf("%b\n",2);
	ft_printf("%b\n",1);

	return (0);
}
