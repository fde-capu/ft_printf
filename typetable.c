/* ******************************************* */
/*                                             */
/*                     |:|::::::|:::|:|::|::|| */
/* typetable.c         :|:|:||:||::::||::|:||| */
/*                     :||||:::|||::||||||:|:: */
/*     ::::|: <::::|:>                         */
/*                                             */
/* C20200207152631 ::::|:                      */
/* U20200207181011 ::||:|                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"

void	init_typetable(void)
{
	tt = ft_calloc(sizeof(t_typetable), 1);
	return ;
}

void	reset_typetable(void)
{
	ft_bzero(tt, sizeof(t_typetable));
	return ;
}

void	print_typetable(void)
{
	if (tt->tt_char)
			ft_putchar_fd(tt->tt_char, FDOUT);
	if (tt->tt_string)
			ft_putstr_fd(tt->tt_string, FDOUT);
	if (tt->tt_pointer)
//			print pointer address
	reset_typetable();
}

int		maketable(char *s)
{
	int	c;

	reset_typetable();
	c = 1;
	s++;
	while (ft_strinset(s, "cspdiuxX%"))
	{
		if (*s == '%')
			ft_putchar_fd('%', FDOUT);
		if (*s == 'c')
			ft_putchar_fd('$', FDOUT);
		c++;
		s++;
	}
	return (c == 1 ? -1 : c);
}

int		joker(char *s)
{
	if (ft_strcmp(s, "%"))
	{
		return (maketable(s));
	}
	ft_putchar_fd(*s, FDOUT);
	return (1);
}
