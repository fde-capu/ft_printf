/* ******************************************* */
/*                                             */
/*                     |:|::::::|:::|:|::|::|| */
/* typetable.c         :|:|:||:||::::||::|:||| */
/*                     :||||:::|||::||||||:|:: */
/*     ::::|: <::::|:>                         */
/*                                             */
/* C20200207152631 ::::|:                      */
/* U20200211094718 ||:|||                      */
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
	g_tt->tt_string = 0;
	g_tt->tt_char = 0;
	g_tt->tt_getstring = 0;
	g_tt->tt_getchar = 0;
	g_tt->tt_pointer = 0;
	g_tt->tt_int = 0;
	g_tt->tt_uint = 0;
	g_tt->tt_zero_flag = 0;
	g_tt->tt_alignleft = 0;
	g_tt->tt_precision = 0;
	g_tt->tt_width = 0;
	g_tt->tt_read_width = 0;
	g_tt->tt_read_precision = 0;
	return ;
}

void	print_typetable(void)
{
	char			*str;
	char			chr;

	str = 0;
	chr = 0;
	if (g_tt->tt_string)
		str = g_tt->tt_string;
//	if (g_tt->tt_pointer)
//			print pointer address
	if (g_tt->tt_int)
		str = ft_itoa(g_tt->tt_int);
	if (g_tt->tt_uint)
		str = ft_uitoa(g_tt->tt_uint);
	if ((g_tt->tt_width) && (!g_tt->tt_alignleft))
		ft_repchar_fd((g_tt->tt_zero_flag ? '0' : ' '), g_tt->tt_width - (str ? ft_strlen(str) : 1), FDOUT);
/*
**
*/
	if (str)
		ft_putstr_fd(str, FDOUT);
	else
	{
		chr = g_tt->tt_char;
		ft_putchar_fd(chr, FDOUT);
	}
/*
** 
*/
	if ((g_tt->tt_width) && (g_tt->tt_alignleft))
		ft_repchar_fd(' ', g_tt->tt_width - (str ? ft_strlen(str) : 1), FDOUT);
}

int		maketable(char *s)
{
	int	c;
	int	precision;

	reset_typetable();
	c = 1;
	precision = 0;
	s++;
/*
** %[flags]<width><precision><length>[conversion char]
*/
	if (*s == '%')		// % exepction
	{
		g_tt->tt_string = "%";
		return (2);
	}
	while (ft_chrinset(s, "-0"))	// % flags
	{
		if (*s == '-')
			g_tt->tt_alignleft = 1;
		if (*s == '0')
			g_tt->tt_zero_flag = 1;
		c++;
		s++;
	}
	while (ft_chrinset(s, "0123456789*"))		// width
	{
		if (*s == '*')
			g_tt->tt_read_width = 1;
		g_tt->tt_width = g_tt->tt_width ? g_tt->tt_width : ft_atoi(s);
		c++;
		s++;
	}
	while (ft_chrinset(s, ".1234567890*"))	// precision
	{
		if (*s == '*')
			g_tt->tt_read_precision = 1;
		g_tt->tt_precision = 1;
		precision = precision ? precision : ft_atoi(s);
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
			g_tt->tt_getchar = 1;
		if (*s == 's')
			g_tt->tt_getstring = 1;
		if (*s == 'p')
			g_tt->tt_pointer = g_tt;
		if (*s == 'd')
			g_tt->tt_int = 1;
		if (*s == 'i')
			g_tt->tt_int = 2;
		if (*s == 'u')
			g_tt->tt_uint = 1;
		if (*s == 'x')
			g_tt->tt_int = 4;
		if (*s == 'X')
			g_tt->tt_int = 5;
		c++;
		s++;
	}
	return (c == 1 ? -1 : c);
}
