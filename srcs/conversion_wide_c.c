/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_wide_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:49:30 by agusev            #+#    #+#             */
/*   Updated: 2019/03/15 20:49:33 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*conversion_wide_c(va_list *arg, int *length, t_flags *flags)
{
	wchar_t		tmp_chr;
	char		chr;
	char		*str;

	tmp_chr = va_arg(*arg, wint_t);
	chr = (char)tmp_chr;
	if (chr == '\0')
	{
		(*length)++;
		flags->null_char = 1;
		str = ft_strnew(1);
	}
	else
		str = ft_bchar(1, chr);
	return (str);
}
