/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:47:54 by agusev            #+#    #+#             */
/*   Updated: 2019/03/15 20:50:52 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf1(const char *s, int i)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)malloc(sizeof(char) + 1);
	tmp1[0] = *s;
	tmp1[1] = '\0';
	tmp2 = ft_strjoin(h_word, s);
	if (s != NULL)
		free(s);
	s = ft_strjoin(h_word, s);
	h_word = s;
	free(tmp1);
}
