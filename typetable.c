/* ******************************************* */
/*                                             */
/*                     |:|::::::|:::|:|::|::|| */
/* typetable.c         :|:|:||:||::::||::|:||| */
/*                     :||||:::|||::||||||:|:: */
/*     ::::|: <::::|:>                         */
/*                                             */
/* C20200207152631 ::::|:                      */
/* U20200207154048 :||:||                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"

void		init_typetable(void)
{
	tt = ft_calloc(sizeof(t_typetable), 1);
	return ;
}

void		reset_typetable(void)
{
	ft_bzero(tt, sizeof(t_typetable));
	return ;
}

void		print_typetable(void)
{
	if (tt->tt_char)
			ft_putchar_fd(tt->tt_char, FDOUT);
	if (tt->tt_string)
			ft_putstr_fd(tt->tt_string, FDOUT);
	if (tt->tt_pointer)
//			print pointer address
	reset_typetable();
}

int		joker(char **str)
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
	if (!ft_strncmp(*str, "%p", 2))
	{
		*str += 2;
		return (3);
	}
	if (!ft_strncmp(*str, "%d", 2))
	{
		*str += 2;
		return (4);
	}
	if (!ft_strncmp(*str, "%i", 2))
	{
		*str += 2;
		return (5);
	}
	if (!ft_strncmp(*str, "%u", 2))
	{
		*str += 2;
		return (6);
	}
	if (!ft_strncmp(*str, "%x", 2))
	{
		*str += 2;
		return (7);
	}
	if (!ft_strncmp(*str, "%X", 2))
	{
		*str += 2;
		return (8);
	}
	if (!ft_strncmp(*str, "%%", 2))
	{
		*str += 2;
		return (9);
	}
	return (0);
}

