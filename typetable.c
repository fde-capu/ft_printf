/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:12:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 08:07:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_typetable(void)
{
	g_tt = g_tt ? ft_calloc(1, 1) : g_tt;
	free(g_tt);
	g_tt = ft_calloc(sizeof(t_typetable), 1);
	return ;
}

void	reset_typetable(void)
{
	t_typetable	*temp;
	temp = ft_calloc(sizeof(t_typetable), 1);
	free(g_tt);
	g_tt = temp;
	return ;
}

char	*makestr(void)
{
	char	*str;

	str = 0;
	str = TTS ? TTS : str;
	str = TTI ? ft_itoa(TTI) : str;
	str = TTU && !TBT ? ft_uitoa(TTU) : str;
	str = TTU && TBT ? ft_dtob(TTU, TBT) : str;
	str = TUC ? ft_ucase(str) : str;
	str = TTL && !TUL ? ft_ltoa(TTL) : str;
	str = TUL ? ft_ultoa(TUL) : str;
	str = TPT ? ft_dtob((long unsigned int)TPT, 16) : str;
	if (TTZ && NEG)
	{
		ft_putchar_fd('-', FDOUT);
		TTW -= TTW ? 1 : 0;
		str++;
	}
	return (str);
}

void	makealigns(char *str)
{
	if ((str) && (TTW > TTZ + STRL) && (!TAL))
		ft_repchar_fd(' ', TTW - TTZ - STRL, FDOUT);
	if ((str) && (TTZ) && (NEG))
	{
		ft_putchar_fd('-', FDOUT);
		ft_repchar_fd('0', TTZ, FDOUT);
		str++;
	}
	if ((str) && (TTZ) && (!NEG))
		ft_repchar_fd('0', TTZ, FDOUT);
	if ((!str) && (TTW > 1))
		ft_repchar_fd(' ', TTW - 1, FDOUT);
	if (!TGC)
		ft_putstr_fd(str, FDOUT);
	else
		ft_putchar_fd(TTC, FDOUT);
	if ((str) && (TTW > TTZ + STRL) && (TAL))
		ft_repchar_fd(' ', TTW - TTZ - STRL, FDOUT);
}

void	print_typetable(void)
{
	char	*str;

	str = makestr();
	if (TPT)
		ft_putstr_fd("0x", FDOUT);
	TTZ = TTZ && !TTP && !TTW ? 0 : TTZ;
	TTZ = TTZ && TTW > STRL ? TTW - STRL : TTZ;
	TTZ = !TTW && TTP ? TTP - STRL : TTZ;
	TTZ = TTW && TTP ? TTP - STRL : TTZ;
	TTW -= TTW && TTP && NEG ? 1 : 0;
	makealigns(str);
}

/*
** %[flags]<width><precision><length>[conversion char]
** (bonus) length (l, ll, h, hh) cplusplus.com/reference/cstdio/printf
*/

int		maketable(char *s)
{
	int	c;
	int	t;

	init_typetable();
	c = 1;
	s++;
	if (*s == '%')
		TTS = "%";
	if (*s == '%')
		return (2);
	t = make_flags(s);
	c += t;
	s += t;
	t = make_width(s);
	c += t;
	s += t;
	t = make_precision(s);
	c += t;
	s += t;
	t = make_length(s);
	c += t;
	s += t;
	t = make_conversion(s);
	c += t;
	s += t;
	return (c == 1 ? -1 : c);
}
