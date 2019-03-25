/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:59:57 by agusev            #+#    #+#             */
/*   Updated: 2019/03/24 21:14:53 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			hashtag;
	int			right_padding;
	int			zero_padding;
	int			width;
	int			precision;
	int			precision_exist;
	int			null_char;
	int			float_f;
	int			float2;
	int			float3;
	int			length;
	char		conversion;
	char		*format;
}				t_flags;

// main print

int				ft_printf(const char *format, ...);

// flags

char			*apply_flags(char *answer, t_flags *flags, \
					int *length, char **str);
int				parse_flags(char **format, t_flags *flags, va_list *arg);
char			*handling_flags(char **format, t_flags *flags);

// conversions

char			*conversions(t_flags *flags, va_list *arg, \
					int *length, char **str);
char			*conversions_extra(t_flags *flags, va_list *arg, char *answer);
char			*conversion_c(va_list *arg, int *length, t_flags *flags);
char			*conversion_wide_c(va_list *arg, int *length, t_flags *flags);
char			*conversion_wide_s(va_list *arg);
char			*conversion_s(va_list *arg);
char			*conversion_b(va_list *arg, t_flags *flags);
char			*conversion_p(va_list *arg);
char			*conversion_d_i(va_list *arg, t_flags *flags);
char			*conversion_o_cap_o(va_list *arg, t_flags *flags);
char			*conversion_x_cap_x(va_list *arg, t_flags *flags);
char			*conversion_u_cap_d_cap_u(va_list *arg, t_flags *flags);
char			*convers_f(va_list *args, t_flags *f);

// formats

char			*handling_format(char **format, t_flags *flags);
char			*handling_precision(char **format, t_flags *flags, \
					va_list *arg);
char			*handling_width(char **format, t_flags *flags, va_list *arg);


// adjust parameters

char			*adding_width(t_flags *flags, char *str);
int				adding_width_wide(t_flags *flags, int length_str);
char			*adding_width_null_char(t_flags *flags, char *answer, \
					int *length, char **str);
char			*adding_plus(t_flags *flags, char *str);
char			*adding_space(t_flags *flags, char *str);
char			*adding_minus(t_flags *flags, char *str);
char			*adding_precision_string(t_flags *flags, char *str);
char			*adding_precision_number(t_flags *flags, char *str);

// extra functions

char			*filler(int c, int len);

#endif
