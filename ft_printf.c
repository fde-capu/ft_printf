/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200203220244 :|:|||                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pexe(va_list a, void *x)
{
	return ;
}

int		ft_printf(const char *fmt, ...)
{
	va_list	a;

	va_start(a, (char *)fmt);
	while (*fmt)
	{
		//pexe(a, "int");
		ft_putchar_fd(*fmt, FDOUT);
		fmt++;
	}
	va_end(a);
	return (1);
}
