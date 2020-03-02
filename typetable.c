/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:12:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 15:27:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_typetable(void)
{
	ft_putstr("|alignl:");
	ft_putstr(ft_itoa(g_f->alignl));
	ft_putstr("|zeros:");
	ft_putstr(ft_itoa(g_f->zeros));
	ft_putstr("|width:");
	ft_putstr(ft_itoa(g_f->width));
	ft_putstr("|precision:");
	ft_putstr(ft_itoa(g_f->precision));
	ft_putstr("|type:");
	ft_putstr(&g_f->type);
	ft_putstr("|");
}

void	init_typetable(void)
{
	free(g_f);
	g_f = ft_calloc(sizeof(t_typetable), 1);
	return ;
}

char	*format_len(char *str)
{
	int		len;
	int		l;
	char	fill;
	int		neg;

	neg = *str == '-' ? 1 : 0;
	if (g_f->zeros && !g_f->precision)
	{
		g_f->precision = g_f->width;
		g_f->precision -= neg ? 1 : 0;
	}
	g_f->zeros = g_f->precision ? 1 : g_f->zeros;
	g_f->precision += neg ? 1 : 0;
	fill = g_f->zeros ? '0' : ' ';
	len = g_f->precision;
	l = ft_strlen(str);
	str += neg;
	if (l < len)
		str = ft_strcat(ft_repchar(fill, len - l), str);
	str = neg ? ft_strcat("-", str) : str;
	len = g_f->width;
	l = ft_strlen(str);
	if ((l < len) && (!g_f->alignl))
		str = ft_strcat(ft_repchar(' ', len - l), str);
	if ((l < len) && (g_f->alignl))
		str = ft_strcat(str, ft_repchar(' ', len - l));
	return (str);
}
