/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:40:39 by agusev            #+#    #+#             */
/*   Updated: 2019/03/24 22:06:59 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_update(char *str, char *update)
{
	char *tmp;

	tmp = malloc(ft_strlen(update) + 1);
	tmp = update;
	if (str != NULL)
		free(str);
	str = update;
	return (str);
}
