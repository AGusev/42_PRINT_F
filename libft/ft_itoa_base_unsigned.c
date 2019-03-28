/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:26:48 by agusev            #+#    #+#             */
/*   Updated: 2019/03/27 20:46:48 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*itoa_filler(char *tab, uintmax_t value, int base)
{
	uintmax_t			tmp;
	int					size;
	char				*str;

	size = 0;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % base];
		size--;
		value = value / base;
	}
	return (str);
}

char					*ft_itoa_base_unsigned(uintmax_t value, int base)
{
	char				*str;
	char				*tab;

	str = NULL;
	tab = "0123456789abcdef";
	str = itoa_filler(tab, value, base);
	return (str);
}

