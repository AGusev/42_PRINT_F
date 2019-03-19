/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_wide_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:35:20 by agusev	           #+#    #+#             */
/*   Updated: 2019/03/18 21:13:07 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printing_string_wide(wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		++i;
	}
	return (i);
}
