/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:12:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/03 23:42:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_ttable(void)
{
	ft_putstr("|a:");
	ft_putstr(ft_itoa(g_f->a));
	ft_putstr("|z:");
	ft_putstr(ft_itoa(g_f->z));
	ft_putstr("|w:");
	ft_putstr(ft_itoa(g_f->w));
	ft_putstr(":");
	ft_putstr(ft_itoa(g_f->wd));
	ft_putstr("|p:");
	ft_putstr(ft_itoa(g_f->p));
	ft_putstr(":");
	ft_putstr(ft_itoa(g_f->pd));
	ft_putstr("-");
	ft_putstr(ft_itoa(g_f->pn));
	ft_putstr("|t:");
	ft_putstr(&g_f->t);
	ft_putstr("|\t");
}

void	init_ttable(void)
{
	free(g_f);
	g_f = ft_calloc(sizeof(t_ttable), 1);
	return ;
}

char	*tweaks(char *str, int neg)
{
	str = ft_stridentical(str, "0") && g_f->pd == 2 ? "" : str;
	g_f->a = g_f->w < 0 ? 1 : g_f->a;
	g_f->w = ft_abs(g_f->w);
	str = ft_stridentical(str, "0") && g_f->pd && g_f->pd != 2 && g_f->p == 0 ? "" : str;
	g_f->p = g_f->z && !g_f->pd && !g_f->a ? g_f->w : g_f->p;
	g_f->z = g_f->pd && g_f->p > 0 ? 1 : g_f->z;
	g_f->p += neg && g_f->pd ? 1 : 0;
	g_f->pn = g_f->p < 0 ? 1 : 0;
	g_f->p = g_f->wd ? ft_abs(g_f->p) : g_f->p;
	g_f->p = g_f->wd && !g_f->w && g_f->pn ? g_f->w : g_f->p;
	g_f->w = !g_f->wd ? g_f->p : g_f->w;
	return (str);
}

char	*format_len(char *str)
{
	int		l;
	char	fill;
	int		neg;

	if (!str)
		return (NULL);
	neg = *str == '-' ? 1 : 0;
	str = tweaks(str, neg);
	fill = g_f->z ? '0' : ' ';
	l = ft_strlen(str);
	str += neg;
	if ((l < g_f->p \
		&& !(g_f->p > g_f->w)
		&& (!g_f->a || !g_f->pn) \
		&& !(g_f->w < g_f->p && !g_f->z)) \
		|| (l < g_f->p && g_f->pd && g_f->z && !g_f->pn))
		str = ft_strcat(ft_repchar(fill, g_f->p - l), str);
	str = neg ? ft_strcat("-", str) : str;
	l = ft_strlen(str);
	if ((l < g_f->w) && (!g_f->a))
		str = ft_strcat(ft_repchar(' ', g_f->w - l), str);
	if ((l < g_f->w) && (g_f->a))
		str = ft_strcat(str, ft_repchar(' ', g_f->w - l));
	return (str);
}
