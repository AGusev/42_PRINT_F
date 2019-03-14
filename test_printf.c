/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:59:02 by agusev            #+#    #+#             */
/*   Updated: 2019/03/14 15:16:39 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/test_printf.h"
#include <stdio.h>

int			my_printf(const char *format, ...)
{
	int			i;
	int			nb;
	va_list		arg;

	i = 0;
	h_count = 0;
	nb = 0;
	va_start(arg, format);
	start_printf(arg, format);
	nb = ft_strlen(h_word);
	write(1, h_word, h_count);
	va_end(arg);
	return (nb + h_count);
}

void		start_printf(va_list arg, char *format)
{
	int i;

	i = 0;
	h_word = ft_strnew(0);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_printf1(format, i);
		}
		if (format[i] == '%' && format[i] != '\0')
		{
			if (format[i + 1] != '\0')
				i++;
			ft_printf2(arg, format, &i);
		}
	}
}

int			main(int ac, char *av[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("%d\n", ac);
	while (++j <= ac)
	{
		my_printf("%s\n", av[j]);
		write(1, "\n", 1);
	}
	printf("%d\n", ac);
	while (++i <= ac)
		printf("%s\n", av[i]);
}
