/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:39:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/11 15:28:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <flag><w><p><length><conversion>
*/

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
	int				a;
	int				z;
	int				w;
	int				wd;
	int				p;
	int				pd;
	int				pn;
	char			t;
	char			*s;
	char			*so;
	int				c;
	struct s_ttable	*nx;
}				t_ttable;

int				ffeed(char *f, t_ttable *t);
int				ft_printf(const char *a, ...);
int				fprocess(char *p, va_list ap, t_ttable *t);
void			ftpf_render(va_list ap, t_ttable *t);
t_ttable		*init_ttable(void);
int				ftpf_flags(char *p, t_ttable *t);
int				ftpf_width(char *p, t_ttable *t);
int				ftpf_preci(char *p, t_ttable *t);
int				ftpf_lengt(char *p, t_ttable *t);
int				ftpf_forms(char *p, t_ttable *t);
void			format_len(t_ttable *t);
void			tweaks(t_ttable *t, int neg);
int				do_ft_printf(t_ttable *t);
t_ttable		*free_tt(t_ttable *t);

#endif
