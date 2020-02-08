
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200208201833 ||:||:                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_error(char *s, int pos)
{
	ft_putstr_fd(s, FDOUT);
	if (ft_whichar(s, -1) != '\n')
		ft_putchar_fd('\n', FDOUT);
	while (pos--)
		ft_putchar_fd(' ', FDOUT);
	ft_putstr_fd(ERRORMSG, FDOUT);
	return ;
}

int	ft_printf(const char *fmt, ...)
{
	va_list		a;
	char		*s;
	int			i;

	init_typetable();
	s = (char *)fmt;
	va_start(a, fmt);
	while (*s)
	{
		i = 1;
		if (ft_strcmp(s, "%"))
		{
			i = maketable(s);
			if (i == -1)
			{
				ft_printf_error(s, s - fmt);
				free(g_tt);
				return (1);
			}
			if (g_tt->tt_getchar)
				g_tt->tt_char = (char)va_arg(a, int);
			if (g_tt->tt_getstring)
				g_tt->tt_string = va_arg(a, char *);
			if (g_tt->tt_pointer)
				g_tt->tt_string = va_arg(a, void *);	// PLACEHOLDER
			if (g_tt->tt_int == 1)
				g_tt->tt_int = va_arg(a, signed int);
			if (g_tt->tt_int == 2)
				g_tt->tt_int = va_arg(a, int); // must also accept 033 (octal) or 0x88 (hex)
			if (g_tt->tt_uint == 1)
				g_tt->tt_uint = va_arg(a, unsigned int);
			if (g_tt->tt_int == 4)
				g_tt->tt_int = va_arg(a, unsigned int); // to hex lcase
			if (g_tt->tt_int == 5)
				g_tt->tt_int = va_arg(a, unsigned int); // to hex ucase
			print_typetable();
		}
		else
			ft_putchar_fd(*s, FDOUT);
		s += i;
	}
	free(g_tt);
	va_end(a);
	return (0);
}
