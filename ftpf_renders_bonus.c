/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_renders_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:23:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/12 19:14:38 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		ftpf_flags(char *p, t_ttable *t)
{
	char	*o;

	o = p;
	while ((p) && (*p) && (ft_chrinset(p, JOKER_FLAGS)))
	{
		t->a = *p == '-' ? 1 : t->a;
		t->z = *p == '0' ? 1 : t->z;
		p++;
	}
	return (p - o);
}

int		ftpf_width(char *p, t_ttable *t)
{
	char	*o;

	o = p;
	while ((p) && (*p) && (ft_chrinset(p, JOKER_WIDTH)))
	{
		if (!t->wd)
			t->w = ft_atoi(p);
		t->wd = 1;
		if (*p == '*')
			t->wd = -1;
		p++;
	}
	return (p - o);
}

int		ftpf_preci(char *p, t_ttable *t)
{
	char	*o;

	o = p;
	if (*p == '.')
	{
		p++;
		t->pd = 2;
		if (ft_chrinset(p, "1234567890"))
		{
			t->pd = 1;
			t->p = ft_atoi(p);
		}
	}
	while ((p) && (*p) && (ft_chrinset(p, JOKER_PRECI)))
	{
		if (*p == '*')
			t->pd = -1;
		p++;
	}
	return (p - o);
}

int		ftpf_lengt(char *p, t_ttable *t)
{
	char	*o;

	o = p;
	while ((p) && (*p) && (ft_chrinset(p, JOKER_LENGT)))
	{
		t->l += *p == 'l' ? 1 : 0;
		t->h += *p == 'h' ? 1 : 0;
		p++;
	}
	t->t = t->t;
	return (p - o);
}

int		ftpf_forms(char *p, t_ttable *t)
{
	char	*o;

	o = p;
	if ((p) && (*p) && (ft_chrinset(p, JOKER_FORMS)))
	{
		t->t = *p;
		p++;
	}
	t->t = t->t ? t->t : '?';
	return (p - o);
}
