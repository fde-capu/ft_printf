/* ******************************************* */
/*                                             */
/*                     |:|::::::|:::|:|::|::|| */
/* typetable.c         :|:|:||:||::::||::|:||| */
/*                     :||||:::|||::||||||:|:: */
/*     ::::|: <::::|:>                         */
/*                                             */
/* C20200207152631 ::::|:                      */
/* U20200217193107 |||:||                      */
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
	TBT = 0;
	TUC = 0;
	return ;
}

void	print_typetable(void)
{
	char	*str;

	str = 0;
	str = TTS ? TTS : str;
	str = TTI && !TBT ? ft_itoa(TTI) : str;
	str = TTI && TBT ? ft_dtob(TTI, TBT) : str;
	str = TUC ? ft_ucase(str) : str;
	str = TTU ? ft_uitoa(TTU) : str;
	str = TTL ? ft_itoa(TTL) : str;
	str = TPT ? ft_dtob((long unsigned int)TPT, 16) : str;
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

/*
** %[flags]<width><precision><length>[conversion char]
*/

int		maketable(char *s)
{
	int	c;

	reset_typetable();
	c = 1;
	s++;
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
		TGC = *s == 'c' ? 1 : TGC;
		TGS = *s == 's' ? 1 : TGS;
		TGP = *s == 'p' ? 1 : TGP;
		TTI = *s == 'd' ? 1 : TTI;
		TTI = *s == 'i' ? 1 : TTI;
		TTI = *s == 'x' ? 2 : TTI;
		TTI = *s == 'X' ? 3 : TTI;
		TTU = *s == 'u' ? 1 : TTU;
		c++;
		s++;
	}
	return (c == 1 ? -1 : c);
}
