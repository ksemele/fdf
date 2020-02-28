/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:39:38 by cghael            #+#    #+#             */
/*   Updated: 2020/01/20 14:39:44 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MAX_LONG 2147483648

static char						f_znaki(unsigned char str)
{
	if (str == ' ' || str == '\t' || str == '\n'
		|| str == '\v' || str == '\f' || str == '\r')
		return (1);
	else
		return (0);
}

static int						ft_base(char c, int base)
{
	char						*s_b;
	char						*s_s;
	int							i;

	i = 0;
	s_b = ft_strdup("0123456789ABCDEF");
	s_s = ft_strdup("0123456789abcdef");
	while (i < base)
	{
		if (c == s_b[i] || c == s_s[i])
		{
			free(s_b);
			free(s_s);
			return (i);
		}
		i++;
	}
	free(s_b);
	free(s_s);
	return (-1);
}

int								ft_atoi_base(const char *str, int base)
{
	unsigned long long int		res;
	int							znak;

	res = 0;
	while (f_znaki(*str))
		str++;
	znak = (*str == '-') ? -1 : 1;
	if ((*str == '+') || (*str == '-'))
		str++;
	while (ft_base(*str, base) >= 0)
	{
		res = res * base;
		res = res + ft_base(*str, base);
		str++;
	}
	if (res > MAX_LONG && znak < 0)
		return (0);
	if (res > MAX_LONG && znak > 0)
		return (-1);
	return ((int)res * znak);
}
