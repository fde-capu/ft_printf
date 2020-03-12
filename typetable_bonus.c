/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:23:05 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/12 17:07:29 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_ttable	*init_ttable(void)
{
	return (ft_calloc(sizeof(t_ttable), 1));
}

void		tweaks(t_ttable *t, int neg)
{
	ft_stridentical(t->s, "0") && t->pd == 2 ? \
		t->s = ft_xlloc(t->s, ft_strnew("")) : 0;
	t->a = t->w < 0 ? 1 : t->a;
	t->w = ft_abs(t->w);
	ft_stridentical(t->s, "0") && t->pd && t->pd != 2 && t->p == 0 ? \
		t->s = ft_xlloc(t->s, ft_strnew("")) : 0;
	t->p = t->z && !t->pd && !t->a ? t->w : t->p;
	t->z = t->pd && t->p > 0 ? 1 : t->z;
	t->p += neg && t->pd && t->p >= 0 ? 1 : 0;
	t->pn = t->p < 0 ? 1 : 0;
	t->p = t->wd ? ft_abs(t->p) : t->p;
	t->p = t->wd && !t->w && t->pn ? t->w : t->p;
	t->p = t->t == 's' && t->pd && t->p + 1 > (int)ft_strlen(t->s) ? \
		(int)ft_strlen(t->s) : t->p;
	t->w = !t->wd ? t->p : t->w;
	t->p = t->w > t->p && t->z && !t->a && t->pn ? t->w : t->p;
	t->s = t->t == 's' && (t->pd == 2 || (t->pd && !t->p)) && !t->pn ? \
		ft_xlloc(t->s, ft_strnew("")) : t->s;
	t->s = t->t == 's' && t->pd && (unsigned long)t->p < ft_strlen(t->s) && \
		!t->pn ? ft_xlloc(t->s, ft_substr(t->s, 0, t->p)) : t->s;
	return ;
}

void		format_len(t_ttable *t)
{
	int		l;
	char	fill;
	int		neg;

	neg = *t->s == '-' && t->t != 'c' && t->t != 's' ? 1 : 0;
	tweaks(t, neg);
	fill = t->z ? '0' : ' ';
	l = ft_strlen(t->s);
	t->s = ft_xlloc(t->s, ft_strnew(t->s + neg));
	t->s = t->t == 'c' && !*t->so ? ft_xlloc(t->s, ft_strnew("#")) : t->s;
	if (*t->s && ((l < t->p && !(t->p > t->w) && (!t->a || !t->pn) \
		&& !(t->w < t->p && !t->z)) \
		|| (l < t->p && t->pd && t->z && !t->pn)) \
		&& !(t->w > t->p && neg && !t->z))
		t->s = ft_strcatxr(ft_repchar(fill, t->p - l), t->s);
	t->s = neg ? ft_strcatxr("-", t->s) : t->s;
	t->s = t->t == 'p' ? ft_strcatxr("0x", t->s) : t->s;
	l = ft_strlen(t->s);
	l += t->t == 'c' && !*t->s ? 1 : 0;
	if ((l < t->w) && (!t->a))
		t->s = ft_strcatx(ft_repchar(' ', t->w - l), t->s);
	if ((l < t->w) && (t->a))
		t->s = ft_strcatx(t->s, ft_repchar(' ', t->w - l));
	t->c += ft_strlen(t->s);
	return ;
}

t_ttable	*free_tt(t_ttable *t)
{
	if (!t->nx)
	{
		free(t->s);
		free(t->so);
		free(t);
		return (0);
	}
	return (free_tt(t->nx));
}

int			do_ft_printf(t_ttable *t)
{
	int	c;
	int	w;

	c = 0;
	while (t->nx)
	{
		t = t->nx;
		w = 0;
		while (w < t->c)
		{
			if (t->t == 'c' && !*t->so && *(t->s + w) == '#')
				write(1, "\0", 1);
			else
				write(1, t->s + w, 1);
			w++;
		}
		c += t->c;
		if (t->t == 'n')
			*t->n = c;
	}
	return (c);
}
