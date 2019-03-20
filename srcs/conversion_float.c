/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:33:42 by agusev            #+#    #+#             */
/*   Updated: 2019/03/19 22:16:40 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_ftoa(float num)
{
	short	i;
	int		tmp;
	short	size;
	char	*str;

	i = 0;
	size = 1;
	tmp = (int)round(num * 100);
	if (num == .0)
		return (ft_strdup("0.00"));
	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
	(tmp < 100) ? ++size : 1;
	num = tmp;
	while (tmp != 0 && ++size)
		tmp /= 10;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[size--] = 0;
	while ((int)num != 0 && ++i)
		(i != 3 && (str[size--] =
		((int)num % 10) + '0')) ? (num /= 10) : (str[size--] = '.');
	(i++ == 2) ? str[size--] = '.' : 1;
	(i++ == 3) ? str[size--] = '0' : 1;
	(size == 0) ? str[0] = '-' : 1;
	return (str);
}
/*
char		*ft_dtoa(double num, short i, short size)
{
	int		tmp;
	char	*str;

	tmp = (int)round(num * 100);
	if (num == .0)
		return (ft_strdup("0.00"));
	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
	(tmp < 10) ? ++size : 1;
	(tmp < 100) ? ++size : 1;
	num = tmp;
	while (tmp != 0 && ++size)
		tmp /= 10;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[size--] = 0;
	while ((int)num != 0 && ++i)
		(i != 3 && (str[size--] = ((int)num % 10) + '0')) ?
		(num /= 10) : (str[size--] = '.');
	(i == 1 && ++i) ? str[size--] = '0' : 1;
	(i++ == 2) ? str[size--] = '.' : 1;
	(i++ == 3) ? str[size--] = '0' : 1;
	(size == 0) ? str[0] = '-' : 1;
	return (str);
}
*/

char			*conversion_float(va_list *arg, t_flags *flags)
{
    char		*answer;
	intmax_t	tmp;

	tmp = va_arg(*arg, uintmax_t);
	if (!ft_strcmp(flags->format, "ll"))
		tmp = (unsigned long long int)tmp;
	else if (!ft_strcmp(flags->format, "l"))
		tmp = (unsigned long int)tmp;
	else if (!ft_strcmp(flags->format, "hh"))
		tmp = (unsigned char)tmp;
	else if (!ft_strcmp(flags->format, "h"))
		tmp = (unsigned short int)tmp;
	else if (!ft_strcmp(flags->format, "j"))
		tmp = (uintmax_t)tmp;
	else if (!ft_strcmp(flags->format, "z"))
		tmp = (size_t)tmp;
	else
		tmp = (unsigned int)tmp;
	
	answer = ft_ftoa(tmp, 8);
	if (flags->hashtag == 1 && tmp != 0)
		answer = ft_update(answer, ft_strjoin("0", answer));
	return (answer);
}