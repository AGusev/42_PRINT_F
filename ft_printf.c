/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:59:02 by agusev            #+#    #+#             */
/*   Updated: 2019/03/22 17:33:47 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print2(const char *format, char *str)
{
	int		length;

	str = ft_update(str, ft_strjoin(str, format));
	write(1, str, ft_strlen(str));
	length = ft_strlen(str);
	free(str);
	return (length);
}

int			ft_printf1(const char *format, va_list *arg, char *str)
{
	t_flags		flags;
	char		*next;
	char		*tmp;
	static int	length;

	if (!length)
		length = 0;
	next = ft_strchr(format, '%');
	if (next == NULL)
		return (length + ft_print2(format, str));
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
	free(flags.format);
	return (ft_printf1(next, arg, str));
}

int			ft_printf(const char *format, ...)
{
	int			length;
	char		*str;
	va_list		arg;

	length = 0;
	str = ft_strnew(1);
	va_start(arg, format);
	length = ft_printf1(format, &arg, str);
	va_end(arg);
	return (length);
}
