/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_renders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:51:40 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 07:52:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_flags(char *s)
{
	int	c;

	c = 0;
	while (ft_chrinset(s, "-0"))
	{
		TAL = *s == '-' ? 1 : TAL;
		TTZ = *s == '0' ? 1 : TTZ;
		c++;
		s++;
	}
	return (c);
}

int		make_width(char *s)
{
	int	c;

	c = 0;
	while (ft_chrinset(s, "0123456789*"))
	{
		TRW = *s == '*' ? 1 : TRW;
		TTW = TTW ? TTW : (unsigned int)ft_atoi(s);
		c++;
		s++;
	}
	return (c);
}

int		make_precision(char *s)
{
	int	c;

	c = 0;
	while (ft_chrinset(s, ".1234567890*"))
	{
		TTP = TTP ? TTP : (unsigned int)ft_atoi(s + 1);
		TRP = *s == '*' ? 1 : TRP;
		c++;
		s++;
	}
	return (c);
}

int		make_length(char *s)
{
	int	c;

	c = 0;
	while (ft_chrinset(s, "lh"))	
	{
		c++;
		s++;
	}
	return (c);
}

int		make_conversion(char *s)
{
	int	c;

	c = 0;
	while (ft_chrinset(s, "cspdiuxX"))
	{
		TGC = *s == 'c' ? 1 : TGC;
		TGS = *s == 's' ? 1 : TGS;
		TGP = *s == 'p' ? 1 : TGP;
		TTI = *s == 'd' ? 1 : TTI;
		TTI = *s == 'i' ? 1 : TTI;
		TTI = *s == 'x' ? 2 : TTI;
		TTI = *s == 'X' ? 3 : TTI;
		TTU = *s == 'u' ? 1 : TTU;
		s++;
		c++;
	}
	return (c);
}
