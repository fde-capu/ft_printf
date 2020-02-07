
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200207153507 :||:|:                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		a;
	char		**f;
	char		*s;
	int			type;

	init_typetable();
	s = (char *)fmt;
	f = &s;
	va_start(a, fmt);
	while (*s)
	{
		type = joker(f);
		if (!type)
			ft_putchar_fd(*s, FDOUT);
		s += type ? 0 : 1;
		if (type == 1)	// %c (char)
			tt->tt_char = va_arg(a, int);
		if (type == 2)	// %s (string)
			tt->tt_string = va_arg(a, char *);
		if (type == 3)	// %p (hex address)
			tt->tt_string = ft_itoa((unsigned long)va_arg(a, long));
		if (type == 4)	// %d
			tt->tt_string = ft_itoa(va_arg(a, int));
//		if (type == 5)	// %i
			// receives integer in decimal, octal or hexadecimal notation
		if (type == 6)	// %u
			tt->tt_string = ft_itoa(va_arg(a, unsigned int));
//		if (type == 7)	// %x
			// %x : hexadecimal lowercase 
//		if (type == 8)	// %X
			// %X : hexadecimal uppercase 
		if (type == 9)	// %%
			tt->tt_char = '%';
		if (type)
			print_typetable();
	}
	va_end(a);
	return (1);
}
