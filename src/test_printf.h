/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:59:57 by agusev            #+#    #+#             */
/*   Updated: 2019/03/13 20:12:37 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PRINTF_H
# define TEST_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int         my_printf(const char *format, ...);
int         counter1(int i, va_list arg, const char *s);
int         counter2(int i, va_list arg, const char *s);
int         counter3(int i, const char *s);
int         counter(int i, va_list arg, const char *s);
size_t  	ft_abs(long long nb);
char		*ft_itoa_base(long long value, int base);
void	    ft_putchar(char c);
void	    ft_putstr(char const *s);
size_t	    ft_strlen(const char *str);

#endif