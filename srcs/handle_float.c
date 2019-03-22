/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:51:31 by agusev            #+#    #+#             */
/*   Updated: 2019/03/22 00:44:03 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	prepare_float(int *sign, long double *n, t_flags *flags)
{
	long double	r;
	int			i;

	i = 0;
	r = 0.5;
	*sign = 0;
	if (*n < 0)
	{
		*n = -(*n);
		*sign = 1;
	}
	flags->float2 = (flags->float2 != 0) ? flags->float2 : 6;
	while (flags->float2 >= 0 && i++ < flags->float2)
		r /= 10;
	*n += r;
}

char	*ft_ftoa(long double n, t_flags *flags)
{
	int		len;
	char	*dst;
	char	*dec;
	int		sign;
	int		pos;

	prepare_float(&sign, &n, flags);
	dec = ft_itoa((long long int)n);
	len = ft_strlen(dec);
	dst = ft_strnew(sign + len + 1 + ((flags->float2 > 0) ? flags->float2 : 0));
	pos = sign;
	ft_strcpy(dst + pos, dec);
	pos += len;
	if (flags->float2 > 0)
		dst[pos++] = '.';
	while (pos <= len + sign + ((flags->float2 > 0) ? flags->float2 : 1))
	{
		dst[pos++] = ((unsigned long long int)(n * 10) % 10) + '0';
		n *= 10;
	}
	if (sign)
		dst[0] = '-';
	flags->float3 = pos;
	return (dst);
}

char		*handle_float(va_list *arg, t_flags *f)
{
	double	tmp;
	char	*answer;

	answer = NULL;
	tmp = va_arg(*arg, long double);
	if (!ft_strcmp(f->format, "l"))
		tmp = (double)tmp;
	else if (!ft_strcmp(f->format, "ll"))
		tmp = (long double)tmp;
	else
		tmp = (long double)tmp;
	answer = ft_update(answer, ft_ftoa4(tmp));
	ft_putstr(answer);
	return (answer);
}