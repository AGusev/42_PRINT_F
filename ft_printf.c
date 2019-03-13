/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:20:00 by agusev            #+#    #+#             */
/*   Updated: 2019/03/12 20:37:42 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int			ft_printf(const char *format, ...)//restrict?
{
	char			*traverse;
	unsigned int	i;
	char			*s;

	traverse = NULL;
//1) Initializing Myprintf's arguments
	va_list arg;
//a variable capable of storing a variable-length argument list--this variable will be of type va_list. va_list is like any other type
	va_start(arg, format);
/*	while (*traverse != '\0')
	{
		*traverse = *format;
		while (*traverse != '%')
		{
			putchar(*traverse);
			traverse++;
		}
		traverse++;
		//2) Fetching and executing arguments
		switch (*traverse)
		{
			case 'c' : i = va_arg(arg, int);//Fetch char argument
				putchar(i);
				break ;

			case 'd' : i = va_arg(arg, int);//Fetch Decimal/Integer argument
						if(i <= 0)
						{
							i = -i;
						putchar('-');
						}
					puts(convert(i, 10));
					break ;

			case 'o': i = va_arg(arg, unsigned int);//Fetch Octal representation
					puts(convert(i, 8));
					break ;

			case 's': s = va_arg(arg, char *);//Fetch string
					puts(s);
					break ;

			case 'x': i = va_arg(arg, unsigned int);//Fetch Hexadecimal representation
					puts(convert(i, 16));
					break ;
		}
		traverse++;
	}
	//3): Closing argument list to necessary clean-up
	va_end(arg);
	return (0);
}
*/

int		main(int ac, char *av[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("%d\n", ac);
	while (++j <= ac)
	{
		printf("%s\n", av[j]);
	}
	printf("%d\n", ac);
	while (++i <= ac)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}

char		*convert(unsigned int num, int base)
{
	static char		octo[] = "0123456789ABCDEF";
	static char		buffer[50];
	char			*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*--ptr = octo[num % base];
		num /= base;
	}
	return (ptr);
}

/*
void		foo(char *fmt, ...)
{
	va_list ap;
	int d;
	char c, *s;

	va_start(ap, fmt);
	while (*fmt)
		switch (*fmt++) {
			case 's':			// string
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':			//int
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':			//char
//need a cast here since va_arg only takes fully promoted types
				c = (char) va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	va_end(ap);
} */
