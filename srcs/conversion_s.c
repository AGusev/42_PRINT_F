/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:49:08 by agusev            #+#    #+#             */
/*   Updated: 2019/03/27 21:19:00 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*conversion_s(va_list *arg)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(*arg, char *);
	if (tmp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(tmp);
//added
	free(str);
	return (str);
}
