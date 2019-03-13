/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:20:21 by agusev            #+#    #+#             */
/*   Updated: 2019/03/12 20:42:31 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include  <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
typedef struct		t_num
{


char			*format;

}					s_num;



#endif
