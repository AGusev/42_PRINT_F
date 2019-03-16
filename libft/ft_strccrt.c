/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:40:22 by agusev            #+#    #+#             */
/*   Updated: 2019/03/15 20:40:28 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccrt(const char *str, char c)
{
	size_t		i;
	size_t		j;
	char		*new;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		++i;
	if (ft_strlen(str) == i - 1)
		return (NULL);
	new = (char *)malloc(sizeof(char) * i + 1);
	j = 0;
	while (j < i)
	{
		new[j] = str[j];
		++j;
	}
	new[j] = '\0';
	return (new);
}
