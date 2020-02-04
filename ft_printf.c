/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:29 by fde-capu          #+#    #+#             */
/* U20200203210153 ||:|:|                      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // REM

void	pexe(va_list a, void *x)
{
	if (ft_strcmp(x, "int"))
		printf(" test >>> int >>> %d\n", *(int *)x); // REM
	return ;
}

int		ft_printf(const char *fmt, ...)
{
	va_list	a;

	va_start(a, (char *)fmt);
	while (*fmt)
	{
		pexe(a, "int");
		fmt++;
	}
	va_end(a);
	return (1);
}
