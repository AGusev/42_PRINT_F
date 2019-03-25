/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:51:52 by agusev            #+#    #+#             */
/*   Updated: 2019/03/24 13:16:05 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_precision1(int *precision1, va_list *arg, \
								t_flags *flags)
{
	int		precision;

	*precision1 = -1;
	precision = va_arg(*arg, int);
	flags->precision = precision;
}

char		*handling_precision(char **format, t_flags *flags, va_list *arg)
{
	int		precision1;

	precision1 = 0;
	if (**format == '.')
		while (**format == '.' || **format == '*' || ft_isdigit(**format))
		{
			flags->precision_exist = 1;
			if (precision1 == 1 && ft_isdigit(**format))
				return (NULL);
			if (precision1 != 0 && **format == '*')
				return (NULL);
			if (**format == '*')
				ft_precision1(&precision1, arg, flags);
			if (ft_isdigit(**format))
			{
				precision1 = -1;
				flags->precision = flags->precision * 10 + **format - 48;
			}
			(*format)++;
		}
	return (*format);
}
