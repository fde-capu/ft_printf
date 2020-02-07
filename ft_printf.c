
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200207183856 |:|||:                      */
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
	i = 0;
	while (*s)
	{
		i = joker(s);
		if (i == -1)
		{
			ft_printf_error(s, s - fmt);
			return (0);
		}
		s += i;
	}
	va_end(a);
	return (1);
}
