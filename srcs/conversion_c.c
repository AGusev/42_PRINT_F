/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:48:33 by agusev            #+#    #+#             */
/*   Updated: 2019/03/17 22:06:51 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*conversion_c(va_list *arg, int *length, t_flags *flags)
{
	char	*str;
	int		tmp;

	tmp = va_arg(*arg, int);
	if (tmp == '\0')
	{
		(*length)++;
		flags->null_char = 1;
		str = ft_strnew(1);
	}
	else
		str = ft_bchar(1, (char)tmp);
	return (str);
}
