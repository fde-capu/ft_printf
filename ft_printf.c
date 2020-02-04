/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200204002305 ||:||:                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			init_typetable(void)
{
	tt = ft_calloc(sizeof(typetable), 1);
	return ;
}

static void			reset_typetable(void)
{
	ft_bzero(tt, sizeof(typetable));
	return ;
}

static void			print_typetable(void)
{
	if (tt->tt_char)
			ft_putchar_fd(tt->tt_char, FDOUT);
	if (tt->tt_string)
			ft_putstr_fd(tt->tt_string, FDOUT);
	reset_typetable();
}

static int			joker(char **str)
{
	if (!ft_strncmp(*str, "%c", 2))
	{
		*str += 2;
		return (1);
	}
	if (!ft_strncmp(*str, "%s", 2))
	{
		*str += 2;
		return (2);
	}
	return (0);
}

int					ft_printf(const char *fmt, ...)
{
	va_list		a;
	char		**f;
	char		*s;
	int			type;

	init_typetable();
	s = (char *)fmt;
	f = &s;
	va_start(a, fmt);
	while (*s)
	{
		type = joker(f);
		if (!type)
			ft_putchar_fd(*s, FDOUT);
		s += type ? 0 : 1;
		if (type == 1)
			tt->tt_char = va_arg(a, int);
		if (type == 2)
			tt->tt_string = va_arg(a, char *);
		if (type)
			print_typetable();
	}
	va_end(a);
	return (1);
}
