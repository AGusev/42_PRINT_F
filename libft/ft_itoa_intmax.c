/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:35:20 by agusev	           #+#    #+#             */
/*   Updated: 2019/03/17 20:50:59 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*itoa_filler(char *tab, long long value, int flag)
{
	long long		tmp;
	int				size;
	char			*str;

	size = 0;
	tmp = ft_abs(value);
	while (tmp /= 10)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % 10)];
		size--;
		value = value / 10;
	}
	return (str);
}

char				*ft_itoa_intmax(long long value)
{
	char			*str;
	char			*tab;
	int				flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (value < 0)
		flag = 1;
	str = itoa_filler(tab, value, flag);
	return (str);
}
