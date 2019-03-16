/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:59:02 by agusev            #+#    #+#             */
/*   Updated: 2019/03/14 22:16:05 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/test_printf.h"
#include <stdio.h>

int				ft_printf(const char *format, ...)
{
	int			len;
	char		*str;
	va_list		arg;

	len = 0;
	str = ft_strnew(1);
	va_start(arg, format);
	len = narrow_ft_printf(format, &arg, str);
	va_end(arg);
	return (len);
}

int				narrow_ft_printf(const char *format, va_list *arg, char *str)
{
	t_flags				flags;
	char					*next;
	char					*tmp;
	static int		length;

	if (!length)
		length = 0;
	next = ft_strchr(format, '%');
	if (next == NULL)
		return (length + final_print(format, str));
	tmp = ft_strccrt(format, '%');
	str = ft_update(str, ft_strjoin(str, tmp));
	free(tmp);
	++next;
	ft_bzero(&flags, sizeof(t_flags));
	parse_flags(&next, &flags, arg);
	tmp = conversions(&flags, arg, &length, &str);
	str = ft_update(str, ft_strjoin(str, tmp));
	++next;
	free(tmp);
	free(flags->format);
	return (narrow_ft_printf(next, arg, str));
}

int				final_print(const char *format, char *str)
{
	int		len;

	str = ft_update(str, ft_strjoin(str, format));
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}

/*
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
*/
