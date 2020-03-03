/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_renders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:51:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/03 17:32:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_flags(char *p)
{
	char	*o;

	o = p;
	while ((p) && (*p) && (ft_chrinset(p, JOKER_FLAGS)))
	{
		g_f->a = *p == '-' ? 1 : g_f->a;
		g_f->z = *p == '0' ? 1 : g_f->z;
		p++;
	}
	return (p - o);
}

int		ftpf_w(char *p)
{
	char	*o;

	o = p;
	g_f->w = ft_atoi(p);
	while ((p) && (*p) && (ft_chrinset(p, JOKER_WIDTH)))
	{
		if (*p == '*')
			g_f->wd = -1;
		p++;
	}
	return (p - o);
}

int		ftpf_preci(char *p)
{
	char	*o;

	o = p;
	if (*p == '.')
	{
		p++;
		g_f->pd = 2;
		if (ft_chrinset(p, "123456789"))
		{
			g_f->pd = 1;
			g_f->p = ft_atoi(p);
		}
	}
	while ((p) && (*p) && (ft_chrinset(p, JOKER_PRECI)))
	{
		if (*p == '*')
			g_f->pd = -1;
		p++;
	}
	return (p - o);
}

int		ftpf_lengt(char *p)
{
	char	*o;

	o = p;
	(void)p;
	while ((p) && (*p) && (ft_chrinset(p, JOKER_LENGT)))
		p++;
	return (p - o);
}

int		ftpf_forms(char *p)
{
	char	*o;

	o = p;
	g_f->t = *p;
	p++;
	return (p - o);
}
