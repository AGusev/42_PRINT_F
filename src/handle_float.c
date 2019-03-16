/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:51:31 by agusev            #+#    #+#             */
/*   Updated: 2019/03/15 20:51:36 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prepare_float(int *sign, long double *n, t_arg *f)
{
	long double	pi;
	int			i;

	i = 0;
	pi = 0.5;
	*sign = 0;
	if (*n < 0)
	{
		*n = -(*n);
		*sign = 1;
	}
	f->pre_nb = (f->pre_nb != 0) ? f->pre_nb : 6;
	while (f->pre_nb >= 0 && i++ < f->pre_nb)
		pi /= 10;
	*n += pi;
}

char	*ft_ftoa(long double n, t_arg *f)
{
	int		len;
	char	*dst;
	char	*dec;
	int		sign;
	int		pos;

	prepare_float(&sign, &n, f);
	dec = ft_itoa((long long int)n);
	len = ft_strlen(dec);
	dst = ft_strnew(sign + len + 1 + ((f->pre_nb > 0) ? f->pre_nb : 0));
	pos = sign;
	ft_strcpy(dst + pos, dec);
	pos += len;
	if (f->pre_nb > 0)
		dst[pos++] = '.';
	while (pos <= len + sign + ((f->pre_nb > 0) ? f->pre_nb : 1))
	{
		dst[pos++] = ((unsigned long long int)(n * 10) % 10) + '0';
		n *= 10;
	}
	if (sign)
		dst[0] = '-';
	f->print_count = pos;
	return (dst);
}

int		handle_float(va_list list, t_arg *arg)
{
	double	n;
	char	*str;

	if (arg->length == ll)
		n = (long double)va_arg(list, long double);
	else
		n = (double)va_arg(list, double);
	str = NULL;
	str = ft_itoa(n, arg);
	ft_putstr(str);
	return (arg->print_count);
}
