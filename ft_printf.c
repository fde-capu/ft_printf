/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 08:15:28 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:17:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ftpf_render(va_list ap)
{
	char		*str;
	char		*out;

	str = ft_strcat("", "");
	g_f->type = g_f->type == 'i' ? 'd' : g_f->type;
	g_f->width = g_f->width == -1 ? va_arg(ap, int) : g_f->width;
	g_f->precision = g_f->precision == -1 ? va_arg(ap, int) : g_f->precision;
	str = g_f->type == '%' ? ft_strcat(str, "%") : str;
	str = g_f->type == 'd' ? ft_strcat(str, ft_itoa(va_arg(ap, int))) : str;
	str = g_f->type == 'c' ? ft_strchrcat(str, (char)va_arg(ap, int)) : str;
	str = g_f->type == 's' ? va_arg(ap, char *) : str;
	str = g_f->type == 'p' ? \
		ft_strcat("0x", ft_dtob(va_arg(ap, long long), 16)) : str;
	str = g_f->type == 'u' ? ft_uitoa(va_arg(ap, unsigned int)) : str;
	str = g_f->type == 'X' ? \
		ft_ucase(ft_dtob(va_arg(ap, unsigned int), 16)) : str;
	str = g_f->type == 'x' ? ft_dtob(va_arg(ap, unsigned int), 16) : str;
	out = format_len(str);
	return (out);
}

char	*fprocess(char *p, va_list ap)
{
	char	*str;
	char	*o;

	o = p;
	p++;
	p += ftpf_flags(p);
	p += ftpf_width(p);
	p += ftpf_preci(p);
	p += ftpf_lengt(p);
	p += ftpf_forms(p);
	str = ft_strcat("", ftpf_render(ap));
	return (str);
}

int		count_jokers(char *f)
{
	char	*o;

	o = f;
	if ((*f == '%') && (*(f + 1) == '%'))
		return (1);
	f++;
	while (ft_chrinset(f, JOKER_FLAGS))
		f++;
	while (ft_chrinset(f, JOKER_WIDTH))
		f++;
	while (ft_chrinset(f, JOKER_PRECI))
		f++;
	while (ft_chrinset(f, JOKER_LENGT))
		f++;
	return (f - o);
}

int		ft_printf(const char *full, ...)
{
	va_list	ap;
	char	*f;
	char	*out;

	out = ft_strcat("", "");
	va_start(ap, full);
	f = (char *)full;
	while ((f) && (*f))
	{
		if (*f == '%')
		{
			init_typetable();
			out = ft_strcat(out, fprocess(f, ap));
			f += count_jokers(f);
		}
		else
			out = ft_strchrcat(out, *f);
		f++;
	}
	va_end(ap);
	ft_putstr(out);
	return (ft_strlen(out));
}
