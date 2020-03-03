/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typetable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:12:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/03 17:41:50 by fde-capu         ###   ########.fr       */
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
	(void)neg;
	return (str);
}

char	*format_len(char *str)
{
	int		len;
	int		l;
	char	fill;
	int		neg;

	if (!str)
		return (NULL);
	neg = *str == '-' ? 1 : 0;
	str = tweaks(str, neg);
	fill = g_f->z ? '0' : ' ';
	len = g_f->p;
	l = ft_strlen(str);
	str += neg;
	if (l < len)
		str = ft_strcat(ft_repchar(fill, len - l), str);
	str = neg ? ft_strcat("-", str) : str;
	len = g_f->w;
	l = ft_strlen(str);
	if ((l < len) && (!g_f->a))
		str = ft_strcat(ft_repchar(' ', len - l), str);
	if ((l < len) && (g_f->a))
		str = ft_strcat(str, ft_repchar(' ', len - l));
	return (str);
}
