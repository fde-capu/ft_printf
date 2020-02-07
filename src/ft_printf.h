/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:49:13 by fde-capu          #+#    #+#             */
/* U20200205190816 |||::|                      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.a"
# include <stdio.h> // REM
# define FDOUT 1

typedef struct typetable
{
	char	tt_char;
	char	*tt_string;
	void	*tt_pointer;
} typetable;
typetable	*tt;

int			ft_printf(const char *a, ...);

#endif
