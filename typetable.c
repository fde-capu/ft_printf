/* ******************************************* */
/*                                             */
/*                     |:|::::::|:::|:|::|::|| */
/* typetable.c         :|:|:||:||::::||::|:||| */
/*                     :||||:::|||::||||||:|:: */
/*     ::::|: <::::|:>                         */
/*                                             */
/* C20200207152631 ::::|:                      */
/* U20200213184219 |::|:|                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"

void	init_typetable(void)
{
	g_tt = ft_calloc(sizeof(t_typetable), 1);
	return ;
}

void	reset_typetable(void)
{
	TTS = 0;
	TTC = 0;
	TGS = 0;
	TGC = 0;
	TGP = 0;
	TTL = 0;
	TPT = 0;
	TTI = 0;
	TTU = 0;
	TTZ = 0;
	TAL = 0;
	TTP = 0;
	TTW = 0;
	TRW = 0;
	TRP = 0;
	return ;
}

void	print_typetable(void)
{
	char	*str;

	str = 0;
	str = TTS ? TTS : str;
	str = TPT ? TPT : str;
	str = TTI ? ft_itoa(TTI) : str;
	str = TTU ? ft_uitoa(TTU) : str;
	str = TTL ? ft_ltoh(TTL) : str;
	str = TPT ? ft_ltoh((long unsigned int)TPT) : str;
	if (TTZ && NEG)
	{
		ft_putchar_fd('-', FDOUT);
		TTW -= TTW ? 1 : 0;
		str++;
	}
	if (TPT)
		ft_putstr_fd("0x", FDOUT);
/*
**	Maybe TPT resolution is system dependent. 
*/
	TTZ = TTZ && !TTP && !TTW ? 0 : TTZ;
	TTZ = TTZ && TTW > STRL ? TTW - STRL : TTZ;
	TTZ = !TTW && TTP ? TTP - STRL : TTZ;
	TTZ = TTW && TTP ? TTP - STRL : TTZ;
	TTW -= TTW && TTP && NEG ? 1 : 0;
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
/*
**
*/
	if (!TGC)
		ft_putstr_fd(str, FDOUT);
	else
		ft_putchar_fd(TTC, FDOUT);
/*
** 
*/
	if ((str) && (TTW > TTZ + STRL) && (TAL))
		ft_repchar_fd(' ', TTW - TTZ - STRL, FDOUT);
}

int		maketable(char *s)
{
	int	c;

	reset_typetable();
	c = 1;
	s++;
/*
** %[flags]<width><precision><length>[conversion char]
*/
	if (*s == '%')		// % exepction
	{
		TTS = "%";
		return (2);
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
	while (ft_chrinset(s, "lh"))	// (bonus) length (l, ll, h, hh) cplusplus.com/reference/cstdio/printf
	{
		c++;
		s++;
	}
	while (ft_chrinset(s, "cspdiuxX")) // conversion
	{
		if (*s == 'c')
			TGC = 1;
		if (*s == 's')
			TGS = 1;
		if (*s == 'p')
			TGP = 1;
		if (*s == 'd')
			TTI= 1;
		if (*s == 'i')
			TTI = 2;
		if (*s == 'u')
			TTU = 1;
		if (*s == 'x')
			TTI = 4;
		if (*s == 'X')
			TTI = 5;
		c++;
		s++;
	}
	return (c == 1 ? -1 : c);
}
