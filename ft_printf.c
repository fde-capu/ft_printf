/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200203231505 :::||:                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	joker(char **str)
{
	if (!ft_strncmp(*str, "%c", 2))
	{
		*str += 2;
		return (1);
	}
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	a;
	char	**f;
	char	*s;
	char	*t;
	int		type;

	s = (char *)fmt;
	f = &s;
	va_start(a, fmt);
	while (*s)
	{
		type = joker(f);
		if (!type)
		{
			ft_putchar_fd(*s, FDOUT);
			s++;
		}
		else
		{
			if (type == 1)
			{
				t = va_arg(a, char *);
				ft_putstr_fd(t, FDOUT);
			}
		}
	}
	va_end(a);
	return (1);
}
