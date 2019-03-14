/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:37:28 by agusev            #+#    #+#             */
/*   Updated: 2019/03/14 14:23:32 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

int			counter(int i, va_list arg, const char *s)
{
	char	*counter;
	int		ret;

	ret = 0;
	counter = " ";
	if (s[i] == 's')
	{
		counter = (va_arg(arg, char *));
		if (counter == '\0')
			counter = "(null)";
		ft_putstr(counter);
		ret += ft_strlen(counter);
	}
	if (s[i] == 'c')
	{
		ft_putchar(va_arg(arg, int));
		ret++;
	}
	ret += counter1(i, arg, s);
	ret += counter1(i, arg, s);
	ret += counter3(i, s);
	return (ret);
}

int			counter1(int i, va_list arg, const char *s)
{
	char	*counter;
	int		ret;

	ret = 0;
	counter = " ";
	if (s[i] == 'd' || s[i] == 'i')
	{
		counter = ft_itoa_base(va_arg(arg, int), 10);
		ft_putstr(counter);
		ret += ft_strlen(counter);
	}
	if (s[i] == 'p')
	{
		ft_putstr("0x");
		counter = ft_itoa_base(va_arg(arg, unsigned long long), 16);
		ft_putstr(counter);
		ret += 2 + ft_strlen(counter);
	}
	return (ret);
}

int			counter2(int i, va_list arg, const char *s)
{
	char	*counter;
	int		ret;

	ret = 0;
	counter = " ";
	if (s[i] == 'o')
	{
		counter = ft_itoa_base(va_arg(arg, unsigned int), 8);
		ft_putstr(counter);
		ret += ft_strlen(counter);
	}
	if (s[i] == 'u')
	{
		counter = ft_itoa_base(va_arg(arg, unsigned int), 10);
		ft_putstr(counter);
		ret += ft_strlen(counter);
	}
	if (s[i] == 'x')
	{
		counter = ft_itoa_base(va_arg(arg, unsigned int), 16);
		ft_putstr(counter);
		ret += ft_strlen(counter);
	}
	return (ret);
}

int			counter3(int i, const char *s)
{
	int		ret;

	ret = 0;
	if (s[i] == '%')
	{
		ft_putchar('%');
		ret++;
	}
	return (ret);
}
