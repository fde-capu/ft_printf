/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:12:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/03 16:48:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_typetable(void)
{
	ft_putstr("|a:");
	ft_putstr(ft_itoa(g_f->alignl));
	ft_putstr("|z:");
	ft_putstr(ft_itoa(g_f->zeros));
	ft_putstr("|w:");
	ft_putstr(ft_itoa(g_f->width));
	ft_putstr("|p:");
	ft_putstr(ft_itoa(g_f->precision));
	ft_putstr(":");
	ft_putstr(ft_itoa(g_f->pdef));
	ft_putstr("|t:");
	ft_putstr(&g_f->type);
	ft_putstr("|\t");
}

void	init_typetable(void)
{
	free(g_f);
	g_f = ft_calloc(sizeof(t_typetable), 1);
	return ;
}

char	*tweaks(char *str, int neg)
{
	if (g_f->zeros && !g_f->pdef && !g_f->alignl)
	{
		g_f->precision = g_f->width;
		g_f->precision -= neg ? 1 : 0;
	}
	str = \
		ft_stridentical(str, "0") && ( \
		(g_f->pdef == 2) \
		|| (g_f->pdef == 1 && g_f->precision == 0) \
		) ? "" : str;
	return (str);
}

char	*format_len(char *str)
{
	int		len;
	int		l;
	char	fill;
	int		neg;

	if (!str)
		return (NULL);
	neg = *str == '-' ? 1 : 0;
	str = tweaks(str, neg);
	g_f->zeros = g_f->pdef && g_f->precision ? 1 : g_f->zeros;
	g_f->precision += neg && g_f->precision > 0 ? 1 : 0;
	fill = g_f->zeros ? '0' : ' ';
	len = g_f->precision;
	len *= g_f->width > 0 && g_f->pdef ? -1 : 1;
	l = ft_strlen(str);
	str += neg;
	if (l < len)
		str = ft_strcat(ft_repchar(fill, len - l), str);
	str = neg ? ft_strcat("-", str) : str;
	len = ft_abs(g_f->width);
	l = ft_strlen(str);
	if ((l < len) && (!g_f->alignl))
		str = ft_strcat(ft_repchar(' ', len - l), str);
	if ((l < len) && (g_f->alignl))
		str = ft_strcat(str, ft_repchar(' ', len - l));
	return (str);
}
