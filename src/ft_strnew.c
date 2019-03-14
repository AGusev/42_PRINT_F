/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:04:13 by agusev            #+#    #+#             */
/*   Updated: 2019/03/14 14:39:10 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

char	*ft_strnew(size_t size)
{
	char *new;

	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	new[size] = '\0';
	while (size--)
		new[size] = '\0';
	return (new);
}
