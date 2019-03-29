/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 01:30:19 by agusev            #+#    #+#             */
/*   Updated: 2019/03/29 01:30:21 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_update(char *str, char *update)
{
	char *tmp;

	tmp = update;
	if (str != NULL)
		free(str);
	str = update;
	return (str);
}
