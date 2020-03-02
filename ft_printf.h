/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:39:16 by fde-capu          #+#    #+#             */
/*   Updated: 2020/03/02 16:54:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# define JOKER_FLAGS "-0"
# define JOKER_WIDTH "0123456789*"
# define JOKER_PRECI ".0123456789*"
# define JOKER_LENGT ""
# define JOKER_FORMS "cspdiuxX%"

typedef struct	s_typetable
{
	int		alignl;
	int		zeros;
	int		width;
	int		precision;
	char	type;
}				t_typetable;

t_typetable		*g_f;
void			init_typetable(void);
void			check_typetable(void);
char			*fprocess(char *p, va_list ap);
int				ft_printf(const char *a, ...);
int				ftpf_flags(char *p);
int				ftpf_width(char *p);
int				ftpf_preci(char *p);
int				ftpf_lengt(char *p);
int				ftpf_forms(char *p);
char			*ftpf_render(va_list ap);
char			*format_len(char *str);
int				count_jokers(char *f);
void			tweaks(int neg);

#endif

/*
** <flag><width><precision><length><conversion>
*/
