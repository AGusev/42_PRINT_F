/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:06:37 by agusev            #+#    #+#             */
/*   Updated: 2019/03/22 00:27:25 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_free2(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

char			*ft_strfjoin1(char *str1, char *str2, int a, int b)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		len;
	int		i;

	s1 = str1;
	s2 = str2;
	s3 = NULL;
	if (!s2 && s1)
		s3 = ft_strdup(s1);
	else if (!s1 && s2)
		s3 = ft_strdup(s2);
	else if (s1 && s2 && !(i = 0))
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		s3 = ft_strnew(len);
		while (*s1)
			s3[i++] = *(s1++);
		while (*s2)
			s3[i++] = *(s2++);
		s3[i] = '\0';
	}
	ft_free2((a > 0 ? str1 : NULL), (b > 0 ? str2 : NULL));
	return (s3);
}

size_t			ft_len_untill(const char *str, char c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != c && str[len] != '\0')
		++len;
	return (len);
}

char			*ft_strjoinnchar2(char *s, int n, char c)
{
	char	*new;
	int		len;
	int		i;

	i = -1;
	if (n == 0)
		return (s);
	len = ft_strlen(s);
	if (!(new = (char*)malloc(len + n + 1)))
		return (NULL);
	new[len + n] = '\0';
	while (++i < len && s)
		new[i] = s[i];
	while (n--)
		new[n + i] = c;
	return (new);
}

char			*ft_strjoinnchar(char *s, int n, char c)
{
	char	*new;
	int		len;

	if (n < 0)
		return (ft_strjoinnchar2(s, -n, c));
	len = ft_strlen(s);
	if (!(new = (char*)malloc(len + n + 1)))
		return (NULL);
	new[len + n] = '\0';
	while (s && len--)
		new[len + n] = s[len];
	while (n--)
		new[n] = c;
	return (new);
}

char			*ft_strfjoinnchar(char *s, int n, char c)
{
	char	*new;

	new = ft_strjoinnchar(s, n, c);
	free(s);
	return (new);
}

static int		ft_ll_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++len;
		n *= -1;
	}
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char			*ft_lltoa(long long n)
{
	char	*s;
	int		len;

	len = ft_ll_len(n);
	s = ft_strnew(len);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		n = -n;
		if (n < 0)
			return (ft_strdup("-9223372036854775808"));
		s[0] = '-';
	}
	while (n)
	{
		--len;
		s[len] = '0' + n % 10;
		n /= 10;
	}
	return (s);
}

int				ft_funtill(char *s)
{
	int	i;
	int	len;

	i = 0;
	if (!ft_strchr(s, '.'))
		return (0);
	len = ft_strlen(s) - 1;
	while (s[len - i] == '0')
	{
		s[len - i] = '\0';
		++i;
	}
	if (s[len - i] == '.')
		s[len - i] = '\0';
	return (0);
}

char			*ft_fpreci(char *s, int preci)
{
	char	*new;
	int		len;
	int		len_a;
	int		len_b;

	len = ft_strlen(s);
	len_a = ft_len_untill(s, '.');
	len_b = len - len_a - 1;
	new = ft_strdup(s);
	free(s);
	if (preci == 0)
		new[ft_len_untill(new, '.')] = '\0';
	else if (len_b > preci)
		new[preci + len_a + 1] = '\0';
	else
		new = ft_strfjoinnchar(new, -preci + len_b, '0');
	return (new);
}

char			*ft_ftoa1(long double f)
{
	long long	a;
	long long	b;
	char		*s;
	char		*tmp;

	a = (long long)f;
	f = f - (long double)a;
	b = (int)(f * 1000000);
	if (b < 0)
		b = -b;
	s = ft_lltoa(a);
	s = ft_strfjoinnchar(s, -1, '.');
	tmp = ft_lltoa(b);
	if (6 - ft_strlen(tmp) > 0)
		tmp = ft_strfjoinnchar(tmp, 6 - ft_strlen(tmp), '0');
	s = ft_strfjoin1(s, tmp, 1, 1);
	if (f < 0 && s[0] != '-')
		s = ft_strfjoinnchar(s, 1, '-');
	return (s);
}
