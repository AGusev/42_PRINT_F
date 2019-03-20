/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concersion_float.1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:33:42 by agusev            #+#    #+#             */
/*   Updated: 2019/03/19 22:12:56 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	prepare_float(int *sign, long double *n, t_arg *f)
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
	flags->float_f = (flags->float_f != 0) ? flags->float_f : 6;
	while (flags->float_f >= 0 && i++ < flags->float_f)
		pi /= 10;
	*n += pi;
}

static char	*ft_ftoa(long double n, t_arg *f)
{
	int		len;
	char	*dst;
	char	*dec;
	int		sign;
	int		pos;

	prepare_float(&sign, &n, f);
	dec = ft_itoa((long long int)n);
	len = ft_strlen(dec);
	dst = ft_strnew(sign + len + 1 + ((flags->float_f > 0) ? flags->float_f : 0));
	pos = sign;
	ft_strcpy(dst + pos, dec);
	pos += len;
	if (flags->float_f > 0)
		dst[pos++] = '.';
	while (pos <= len + sign + ((flags->float_f > 0) ? flags->float_f : 1))
	{
		dst[pos++] = ((unsigned long long int)(n * 10) % 10) + '0';
		n *= 10;
	}
	if (sign)
		dst[0] = '-';
	return (dst);
}

char		*conversion_float(va_list *arg, t_flags *flags)
{
	double	n;
	char	*str;
	intmax_t	tmp;

	if (arg->length == ll)
		tmp = (long double)va_arg(list, long double);
	else
		tmp = (double)va_arg(list, double);
	str = NULL;
	str = ft_ftoa(tmp, arg);
	ft_putstr(str);
	return (str);
}
