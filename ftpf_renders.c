/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_renders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:51:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 15:24:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_flags(char *p)
{
	char	*o;

	o = p;
	while ((p) && (*p) && (ft_chrinset(p, JOKER_FLAGS)))
	{
		g_f->alignl = *p == '-' ? 1 : g_f->alignl;
		g_f->zeros = *p == '0' ? 1 : g_f->zeros;
		p++;
	}
	return (p - o);
}

int		ftpf_width(char *p)
{
	char	*o;

	o = p;
	g_f->width = ft_atoi(p);
	while ((p) && (*p) && (ft_chrinset(p, JOKER_WIDTH)))
	{
		if (*p == '*')
			g_f->width = -1;
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
		g_f->precision = ft_atoi(p);
	}
	while ((p) && (*p) && (ft_chrinset(p, JOKER_PRECI)))
	{
		if (*p == '*')
			g_f->precision = -1;
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
	g_f->type = *p;
	p++;
	return (p - o);
}
