/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200203223847 ::|:|:                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pexe(va_list a, void *x)
{
	return ;
}

static char	*joker(char *str)
{
	if (!ft_strncmp(str, "%c", 2))
	{
		return (str + 2 - 1);
	}
	return (str);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	a;
	char	*f;
	char	*t;

	f = (char *)fmt;
	va_start(a, fmt);
	while (*f)
	{
		//pexe(a, "int");
		if (f == joker(f))
			ft_putchar_fd(*f, FDOUT);
		else
		{
			f = joker(f);
			t = va_arg(a, char *);
			ft_putstr_fd(t, FDOUT);
		}
		f++;
	}
	va_end(a);
	return (1);
}
