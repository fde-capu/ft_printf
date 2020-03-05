/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:39:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/05 04:30:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# define JOKER_FLAGS "-0"
# define JOKER_WIDTH "0123456789*"
# define JOKER_PRECI ".0123456789*"
# define JOKER_LENGT ""
# define JOKER_FORMS "cspdiuxX%"

typedef struct	s_ttable
{
	int		a;
	int		z;
	int		w;
	int		wd;
	int		p;
	int		pd;
	int		pn;
	char	t;
//	int		ncc;
}				t_ttable;

t_ttable		*g_f;
void			init_ttable(void);
char			*fprocess(char *p, va_list ap);
int				ft_printf(const char *a, ...);
int				ftpf_flags(char *p);
int				ftpf_w(char *p);
int				ftpf_preci(char *p);
int				ftpf_lengt(char *p);
int				ftpf_forms(char *p);
char			*ftpf_render(va_list ap);
char			*format_len(char *str);
int				count_jokers(char *f);
char			*tweaks(char *str, int neg);
int				tt_cmp(const char *tt, char *str, char *stv);

#endif

/*
** <flag><w><p><length><conversion>
*/
