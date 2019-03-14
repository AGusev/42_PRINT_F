/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:59:02 by agusev            #+#    #+#             */
/*   Updated: 2019/03/13 19:32:14 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"
#include <stdio.h>
#include "libft/libft.h"

int        my_printf(const char *format, ...)
{
	int        i;
	int        ret;
	va_list    arg;

	i = 0;
	ret = 0;
	va_start(arg, format);
	while (format[i] != '\0')
    {
        while (format[i] != '%' && format[i] != '\0')
        {
            ft_putchar(format[i]);
            ret++;
            i++;
        }
        if (format[i] == '%' && format[i] != '\0')
        {
            i++;
            ret += counter(i, arg, format);
        }
        if (format[i] != '\0')
            i++;
    }
	va_end(arg);
	return (ret);
}

int		main(int ac, char *av[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	//	ft_printf("%d\n", ac);
	while (++j <= ac)
	{
		my_printf("%s\n", av[j]);
		write(1, "\n", 1);
	}
	//	printf("%d\n", ac);
	while (++i <= ac)
		printf("%s\n", av[i]);
}
