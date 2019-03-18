/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:59:02 by agusev            #+#    #+#             */
/*   Updated: 2019/03/17 22:46:03 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int				narrow_ft_printf(const char *format, va_list *arg, char *str)
{
	t_flags				flags;
	char				*next;
	char				*tmp;
	static int			len;

	if (!len)
		len = 0;
	next = ft_strchr(format, '%');
	if (next == NULL)
		return (len + final_print(format, str));
	tmp = ft_strccrt(format, '%');
	str = ft_update(str, ft_strjoin(str, tmp));
	free(tmp);
	++next;
	ft_bzero(&flags, sizeof(t_flags));
	parse_flags(&next, &flags, arg);
	tmp = conversions(&flags, arg, &len, &str);
	str = ft_update(str, ft_strjoin(str, tmp));
	++next;
	free(tmp);
	free(flags.format);
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
