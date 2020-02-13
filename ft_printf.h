/* ******************************************* */
/*                                             */
/*                     ||||::::::||||:|||::||| */
/* ft_printf.h         :|::::|:::||:::|:||::|: */
/*                     :||:||:|:|::|:|:||||||: */
/*     |:|::| <|:|::|>                         */
/*                                             */
/* C20200207142351 |:|::|                      */
/* U20200213015728 |::|:|                      */
/*                                             */
/* ******************************************* */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> // REM
# define FDOUT 1
# define ERRORMSG "^~~~ format error\n"
# define TT(X) g_tt->X
# define TTS TT(tt_string)
# define TTI TT(tt_int)
# define TTU TT(tt_uint)
# define TTL TT(tt_long)
# define TTZ TT(tt_zero)
# define TTW TT(tt_width)
# define TRW TT(tt_read_width)
# define TTP TT(tt_precision)
# define TRP TT(tt_read_precision)
# define TPT TT(tt_pointer)
# define TTC TT(tt_char)
# define TAL TT(tt_alignleft)
# define TGC TT(tt_getchar)
# define TGS TT(tt_getstring)
# define TGP TT(tt_getpointer)
# define NEG (*str == '-')
# define STRL ft_strlen(str)

typedef struct s_typetable
{
	char			*tt_string;
	int				tt_getstring;
	char			tt_char;
	int				tt_getchar;
	int				tt_getpointer;
	long			tt_long;
	void			*tt_pointer;// check if its in use
	int				tt_int;
	unsigned int	tt_uint;
	unsigned int	tt_zero;
	int				tt_alignleft;
	unsigned int	tt_precision;
	unsigned int	tt_width;
	int				tt_read_width;
	int				tt_read_precision;
} t_typetable;

t_typetable		*g_tt;
int				ft_printf(const char *a, ...);
void			init_typetable(void);
void			reset_typetable(void);
void			print_typetable(void);
int				maketable(char *s);

#endif
