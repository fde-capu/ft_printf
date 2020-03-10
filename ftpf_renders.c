/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_renders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:51:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/09 15:29:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_flags(char *p, t_ttable *t)
{
	char	*o;

	o = p;
	while ((p) && (*p) && (ft_chrinset(p, JOKER_FLAGS)))
	{
		t->t = *p == '%' && *(p + 1) == '%' ? '%' : t->t;
		t->a = *p == '-' ? 1 : t->a;
		t->z = *p == '0' ? 1 : t->z;
		p++;
	}
	return (p - o);
}

int		ftpf_w(char *p, t_ttable *t)
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
		if (ft_chrinset(p, "123456789"))
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
		p++;
	t->t = t->t;
	return (p - o);
}

int		ftpf_forms(char *p, t_ttable *t)
{
	char	*o;

	o = p;
	while ((p) && (*p) && (ft_chrinset(p, JOKER_FORMS)))
	{
		t->t = *p;
		p++;
	}
	return (p - o);
}
