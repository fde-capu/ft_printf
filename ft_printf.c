
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200218132139 :::::|                      */
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

void	putvar(unsigned int val, unsigned int *adr)
{
	*adr = val;
}

int		ft_printf(const char *fmt, ...)
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
			TTW = TRW ? va_arg(a, unsigned int) : TTW;
			TTP = TRP ? va_arg(a, unsigned int) : TTP;
			TTC = TGC ? (char)va_arg(a, int) : TTC;
			TTS = TGS ? va_arg(a, char *) : TTS;
			TPT = TGP ? va_arg(a, void *) : TPT;
			TTI = TTI ? va_arg(a, int) : TTI;
			TUC = TTU == 3 ? 1 : TUC;
			TBT = TTU > 1 ? 16 : TBT;
			TTU = TTU ? va_arg(a, unsigned int) : TTU;
			TTL = TTL && !TTU ? va_arg(a, signed long) : TTL;
			TUL = TTL && TTU ? va_arg(a, unsigned long) : TUL;
			if (!TPV)
				print_typetable();
			else
				putvar(s - fmt, va_arg(a, unsigned int *));
		}
		else
			ft_putchar_fd(*s, FDOUT);
		s += i;
	}
	free(g_tt);
	va_end(a);
	return (0);
}
