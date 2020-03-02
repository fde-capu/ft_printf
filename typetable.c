<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:12:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 07:59:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/* ******************************************* */
/*                                             */
/*                     |:|::::::|:::|:|::|::|| */
/* typetable.c         :|:|:||:||::::||::|:||| */
/*                     :||||:::|||::||||||:|:: */
/*     ::::|: <::::|:>                         */
/*                                             */
/* C20200207152631 ::::|:                      */
/* U20200218134415 ::|||:                      */
/*                                             */
/* ******************************************* */
>>>>>>> e18398df11a5ef66e39296f48689a369dd6a9a00

#include "ft_printf.h"

void	init_typetable(void)
{
	g_tt = g_tt ? ft_calloc(1, 1) : g_tt;
	free(g_tt);
	g_tt = ft_calloc(sizeof(t_typetable), 1);
	return ;
}

<<<<<<< HEAD
char	*makestr(void)
=======
void	reset_typetable(void)
{
	t_typetable	*temp;
	temp = ft_calloc(sizeof(t_typetable), 1);
	free(g_tt);
	g_tt = temp;
	return ;
}

void	print_typetable(void)
>>>>>>> e18398df11a5ef66e39296f48689a369dd6a9a00
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

<<<<<<< HEAD
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
=======
/*
** %[flags]<width><precision><length>[conversion char]
** Bonus:
** conversions: n f g e (ok: n) 
** flags: l ll h hh
** flags: # + (both have to work)
>>>>>>> e18398df11a5ef66e39296f48689a369dd6a9a00
*/

int		maketable(char *s)
{
	int	c;
	int	t;

	init_typetable();
	c = 1;
	s++;
<<<<<<< HEAD
	if (*s == '%')
=======
	if (*s == '%')		// % exepction
	{
>>>>>>> e18398df11a5ef66e39296f48689a369dd6a9a00
		TTS = "%";
	if (*s == '%')
		return (2);
<<<<<<< HEAD
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
=======
	}
	while (ft_chrinset(s, "-0"))	// % flags
	{
		if (*s == '-')
			TAL = 1;
		if (*s == '0')
			TTZ = 1;
		c++;
		s++;
	}
	while (ft_chrinset(s, "0123456789*"))		// width
	{
		if (*s == '*')
			TRW = 1;
		TTW = TTW ? TTW : (unsigned int)ft_atoi(s);
		c++;
		s++;
	}
	while (ft_chrinset(s, ".1234567890*"))	// precision
	{
		TTP = TTP ? TTP : (unsigned int)ft_atoi(s + 1);
		if (*s == '*')
			TRP = 1;
		c++;
		s++;
	}
	while (ft_chrinset(s, "h"))	// (bonus) length (l, ll, h, hh) cplusplus.com/reference/cstdio/printf
	{
		c++;
		s++;
	}
	while (ft_chrinset(s, "cspdiuxXnl")) // conversion
	{
		TGC = *s == 'c' ? 1 : TGC;
		TGS = *s == 's' ? 1 : TGS;
		TGP = *s == 'p' ? 1 : TGP;
		TTI = *s == 'd' ? 1 : TTI;
		TTI = *s == 'i' ? 1 : TTI;
		TTU = *s == 'u' ? 1 : TTU;
		TTU = *s == 'x' ? 2 : TTU;
		TTU = *s == 'X' ? 3 : TTU;
		TPV = *s == 'n' ? 1 : TPV;
		TTL += *s == 'l' ? 1 : 0;
		TLL = TTL > 1 ? 1 : TLL;
		TTL = TLL ? 0 : TTL;
		TTI = TTL || TLL ? 0 : TTI;
		c++;
		s++;
	}
>>>>>>> e18398df11a5ef66e39296f48689a369dd6a9a00
	return (c == 1 ? -1 : c);
}
