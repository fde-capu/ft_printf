/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:22:53 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/12 19:14:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	bonus_features(va_list ap, t_ttable *t)
{
	long long	a;

	a = t->t == 'n' ? va_arg(ap, long long) : 0;
	t->n = a && t->t == 'n' ? (int *)a : t->n;
}

void	ftpf_render(va_list ap, t_ttable *t)
{
	long long	a;

	t->s = ft_strnew("");
	t->t = t->t == 'i' ? 'd' : t->t;
	t->w = t->wd == -1 ? va_arg(ap, int) : t->w;
	t->wd = t->wd == -1 ? 1 : t->wd;
	t->p = t->pd == -1 ? va_arg(ap, int) : t->p;
	t->pd = t->pd == -1 ? 1 : t->pd;
	t->s = t->t == '%' ? ft_xlloc(t->s, ft_strnew("%")) : t->s;
	t->s = t->t == 'd' && !t->l ? ft_xlloc(t->s, ft_itoa(va_arg(ap, int))) : t->s;
	t->s = t->t == 'd' && t->l == 1 ? ft_xlloc(t->s, ft_ltoa(va_arg(ap, long))) : t->s;
	t->s = t->t == 'd' && t->l == 2 ? ft_xlloc(t->s, ft_lltoa(va_arg(ap, long))) : t->s;
	t->s = t->t == 'c' ? \
		ft_xlloc(t->s, ft_chrtostr((char)va_arg(ap, int))) : t->s;
	a = t->t == 's' ? va_arg(ap, long long) : 0;
	t->s = a ? ft_xlloc(t->s, ft_strnew((char *)a)) : t->s;
	t->s = !a && t->t == 's' ? ft_xlloc(t->s, ft_strnew("(null)")) : t->s;
	t->s = t->t == 'p' ? \
		ft_xlloc(t->s, ft_dtob(va_arg(ap, long long), 16)) : t->s;
	t->s = t->t == 'u' ? \
		ft_xlloc(t->s, ft_uitoa(va_arg(ap, unsigned int))) : t->s;
	t->s = ft_chrinset(&t->t, "Xx") ? \
		ft_xlloc(t->s, ft_dtob(va_arg(ap, unsigned int), 16)) : t->s;
	t->s = t->t == 'X' ? ft_xlloc(t->s, ft_ucase(t->s)) : t->s;
	t->so = ft_strnew(t->s);
	bonus_features(ap, t);
	format_len(t);
	return ;
}

int		fprocess(char *p, va_list ap, t_ttable *t)
{
	char	*o;

	o = p;
	p++;
	if (*p)
	{
		p += ftpf_flags(p, t);
		p += ftpf_width(p, t);
		p += ftpf_preci(p, t);
		p += ftpf_lengt(p, t);
		p += ftpf_forms(p, t);
	}
	ftpf_render(ap, t);
	return (p - o);
}

int		ffeed(char *f, t_ttable *t)
{
	char	*p;
	int		c;

	t->t = '*';
	c = 0;
	p = f;
	while ((p) && (*p) && (*p != '%'))
	{
		c++;
		p++;
	}
	t->s = ft_substr(f, 0, c);
	t->c = c;
	return (c);
}

int		ft_printf(const char *full, ...)
{
	va_list		ap;
	t_ttable	*head;
	t_ttable	*p;
	char		*f;
	int			r;

	head = init_ttable();
	p = head;
	va_start(ap, full);
	f = (char *)full;
	while ((f) && (*f))
	{
		p->nx = init_ttable();
		p = p->nx;
		if (*f == '%')
			f += fprocess(f, ap, p);
		else
			f += ffeed(f, p);
	}
	va_end(ap);
	r = do_ft_printf(head);
	free_tt(head);
	return (r);
}
