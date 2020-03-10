/* ******************************************* */
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:12:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/09 14:02:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ttable	*init_ttable(void)
{
	return (ft_calloc(sizeof(t_ttable), 1));
}

void	tweaks(t_ttable *t, int neg)
{
	ft_stridentical(t->s, "0") && t->pd == 2 ? t->s = ft_xlloc(t->s, ft_strnew("")) : 0;
	t->a = t->w < 0 ? 1 : t->a;
	t->w = ft_abs(t->w);
	ft_stridentical(t->s, "0") && t->pd && t->pd != 2 && t->p == 0 ? t->s = ft_xlloc(t->s, ft_strnew("")) : 0;
	t->p = t->z && !t->pd && !t->a ? t->w : t->p;
	t->z = t->pd && t->p > 0 ? 1 : t->z;
	t->p += neg && t->pd && t->p >= 0 ? 1 : 0;
	t->pn = t->p < 0 ? 1 : 0;
	t->p = t->wd ? ft_abs(t->p) : t->p;
	t->p = t->wd && !t->w && t->pn ? t->w : t->p;
	t->p = t->t == 's' && t->pd && (unsigned long)t->p + 1 > ft_strlen(t->s) ? ft_strlen(t->s) : t->p;
	t->w = !t->wd ? t->p : t->w;
	t->p = t->w > t->p && t->z && !t->a && t->pn ? t->w : t->p;
	t->t == 's' && (t->pd == 2 || (t->pd && !t->p)) && !t->pn ? t->s = ft_xlloc(t->s, ft_strnew("")) : 0;
	t->t == 's' && t->t && t->pd && (unsigned long)t->p < ft_strlen(t->s) && !t->pn ? t->s = ft_xlloc(t->s, ft_substr(t->s, 0, t->p)) : 0;
	t->w = t->t == 's' && ft_stridentical(t->s, "0") && !t->wd ? 1 : t->w;
	t->p = t->t == 's' && ft_stridentical(t->s, "0") && !t->wd ? 1 : t->p;
//	t->w = t->t == 'c' && !*t->s ? t->w - 1 : t->w;	
//	t->c = t->t == 'c' && !*t->s ? 1 : t->c;
//	t->t == 'c' && !*t->s ? t->s = ft_xlloc(t->s, ft_strnew("\0")) : 0;
	return ;
}

void	format_len(t_ttable *t)
{
	int		l;
	char	fill;
	int		neg;

	t->s = t->t == 's' && !*t->s ? ft_xlloc(t->s, ft_strnew("(null)")) : t->s;
	neg = *t->s == '-' && t->t != 'c' && t->t != 's' ? 1 : 0;
	tweaks(t, neg);
	fill = t->z ? '0' : ' ';
	l = ft_strlen(t->s);
	t->s = ft_xlloc(t->s, ft_strnew(t->s + neg));
	if (*t->s && \
		((l < t->p \
		&& !(t->p > t->w)
		&& (!t->a || !t->pn) \
		&& !(t->w < t->p && !t->z)) \
		|| (l < t->p && t->pd && t->z && !t->pn)) \
		&& !(t->w > t->p && neg && !t->z) \
		)
		t->s = ft_strcatxr(ft_repchar(fill, t->p - l), t->s);
	t->s = neg ? ft_strcatxr("-", t->s) : t->s;
	l = ft_strlen(t->s);
	if ((l < t->w) && (!t->a))
		t->s = ft_strcatx(ft_repchar(' ', t->w - l), t->s);
	if ((l < t->w) && (t->a))
		t->s = ft_strcatx(t->s, ft_repchar(' ', t->w - l));
	t->c += ft_strlen(t->s); 
	return ;
}

int		do_ft_printf(t_ttable *t)
{
	int	c;

	c = 0;
	while (t->nx)
	{
		t = t->nx;
		gg = t;
		write(1, t->s, t->c);
		c += t->c;
	}
	return (c);
}
