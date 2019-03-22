/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 00:18:36 by agusev            #+#    #+#             */
/*   Updated: 2019/03/22 00:43:24 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


char	*ft_ftoa4(double n)
{
	int		one;
	int		state;
	char	*ptr;
	char	*ret;
	double	two;

	state = (n < 0) ? 1 : 0;
	ret = ft_itoa(n);
	ptr = ft_strdup(".");
	ret = ft_strfjoin(&ret, &ptr, 3);
	n *= state ? -1 : 1;
	one = (int)n;
	two = n - one;
	while (++state && (size_t)state < (sizeof(n) - 1))
		two *= 10;
	ptr = ft_itoa((int)two);
	ret = ft_strfjoin(&ret, &ptr, 3);
	return (ret);
}

/*
char			*ft_ftoa4(double n, size_t precision)
{
	char		*str;

	str = NULL;
	str = (char *)malloc(sizeof(*str) * ft_str_size(n, precision) + 1);
	if (str)
		ft_convert(str, n, precision);
	return (str);
}

static int		ft_str_size(double n, size_t precision)
{
	int			len;
	int			dot;

	len = 0;
	dot = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	if (precision > 0)
		len++;
	len += precision;
	return (len);
}

static void		ft_convert(char *str, double n, size_t precision)
{
	int			dot;

	dot = 0;
	if (n < 0)
	{
		*str = '-';
		n = -n;
		str++;
	}
	while (n >= 1 && dot++ >= 0)
		n /= 10;
	ft_convert_rest(str, n, precision, dot);
}

static void		ft_convert_rest(char *str, double n, size_t prec, int dot)
{
	size_t		i;

	i = 0;
	while (dot--)
	{
		n *= 10;
		*str = (int)n + '0';
		str++;
		n -= (int)n;
	}
	if (prec > 0)
	{
		*str = '.';
		str++;
		while (i++ < prec)
		{
			n *= 10;
			*str = (int)n + '0';
			str++;
			n -= (int)n;
		}
	}
	*str = '\0';
}
*/