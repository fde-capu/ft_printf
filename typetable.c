/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:12:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/09 07:32:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_ttable(void)
{
	free(g_f);
	g_f = ft_calloc(sizeof(t_ttable), 1);
	return ;
}

char	*tweaks(char *str, int neg)
{
	str = ft_stridentical(str, "0") && g_f->pd == 2 ? ft_xlloc(str, ft_strnew("")) : str;
	g_f->a = g_f->w < 0 ? 1 : g_f->a;
	g_f->w = ft_abs(g_f->w);
	str = ft_stridentical(str, "0") && g_f->pd && g_f->pd != 2 && g_f->p == 0 ? ft_xlloc(str, ft_strnew("")) : str;
	g_f->p = g_f->z && !g_f->pd && !g_f->a ? g_f->w : g_f->p;
	g_f->z = g_f->pd && g_f->p > 0 ? 1 : g_f->z;
	g_f->p += neg && g_f->pd && g_f->p >= 0 ? 1 : 0;
	g_f->pn = g_f->p < 0 ? 1 : 0;
	g_f->p = g_f->wd ? ft_abs(g_f->p) : g_f->p;
	g_f->p = g_f->wd && !g_f->w && g_f->pn ? g_f->w : g_f->p;
	g_f->p = g_f->t == 's' && g_f->pd && (unsigned long)g_f->p + 1 > ft_strlen(str) ? ft_strlen(str) : g_f->p;
	g_f->w = !g_f->wd ? g_f->p : g_f->w;
	g_f->p = g_f->w > g_f->p && g_f->z && !g_f->a && g_f->pn ? g_f->w : g_f->p;
	str = g_f->t == 's' && (g_f->pd == 2 || (g_f->pd && !g_f->p)) && !g_f->pn ? ft_xlloc(str, ft_strnew("")) : str;
	str = g_f->t == 's' && g_f->t && g_f->pd && (unsigned long)g_f->p < ft_strlen(str) && !g_f->pn ? ft_xlloc(str, ft_substr(str, 0, g_f->p)) : str;
	g_f->w = g_f->t == 's' && ft_stridentical(str, "0") && !g_f->wd ? 1 : g_f->w;
	g_f->p = g_f->t == 's' && ft_stridentical(str, "0") && !g_f->wd ? 1 : g_f->p;
	g_f->w = g_f->t == 'c' && !*str ? g_f->w - 1 : g_f->w;	
	g_nc += ft_strlen(str);
	g_nc += g_f->t == 'c' && !*str ? 1 : 0;
	str = g_f->t == 'c' && !*str ? ft_xlloc(str, ft_strnew("\0")) : str;
	return (str);
}

char	*format_len(char *str)
{
	int		l;
	char	fill;
	int		neg;

	str = g_f->t == 's' && !*str ? ft_xlloc(str, ft_strnew("(null)")) : str;
	neg = *str == '-' && g_f->t != 'c' && g_f->t != 's' ? 1 : 0;
	str = tweaks(str, neg);
	fill = g_f->z ? '0' : ' ';
	l = ft_strlen(str);
	str = ft_xlloc(str, ft_strnew(str + neg));
	if (*str && \
		((l < g_f->p \
		&& !(g_f->p > g_f->w)
		&& (!g_f->a || !g_f->pn) \
		&& !(g_f->w < g_f->p && !g_f->z)) \
		|| (l < g_f->p && g_f->pd && g_f->z && !g_f->pn)) \
		&& !(g_f->w > g_f->p && neg && !g_f->z) \
		)
		str = ft_strcatxr(ft_repchar(fill, g_f->p - l), str);
	str = neg ? ft_strcatxr("-", str) : str;
	l = ft_strlen(str);
	if ((l < g_f->w) && (!g_f->a))
		str = ft_strcatx(ft_repchar(' ', g_f->w - l), str);
	if ((l < g_f->w) && (g_f->a))
		str = ft_strcatx(str, ft_repchar(' ', g_f->w - l));
	return (str);
}
