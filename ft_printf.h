/* ******************************************* */
/*                                             */
/*                     ||||::::::||||:|||::||| */
/* ft_printf.h         :|::::|:::||:::|:||::|: */
/*                     :||:||:|:|::|:|:||||||: */
/*     |:|::| <|:|::|>                         */
/*                                             */
/* C20200207142351 |:|::|                      */
/* U20200218132125 |:::::                      */
/*                                             */
/* ******************************************* */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> // REM
# define FDOUT 1
# define ERRORMSG "^~~~ format error\n"
# define TAL g_tt->tt_alignleft
# define TBT g_tt->tt_baseto
# define TGC g_tt->tt_getchar
# define TGP g_tt->tt_getpointer
# define TGS g_tt->tt_getstring
# define TLL g_tt->tt_llong
# define TPT g_tt->tt_pointer
# define TPV g_tt->tt_putvar
# define TRP g_tt->tt_read_precision
# define TRW g_tt->tt_read_width
# define TTI g_tt->tt_int
# define TTS g_tt->tt_string
# define TTL g_tt->tt_long
# define TTP g_tt->tt_precision
# define TTU g_tt->tt_uint
# define TTZ g_tt->tt_zero
# define TTW g_tt->tt_width
# define TTC g_tt->tt_char
# define TUC g_tt->tt_ucase
# define TUL g_tt->tt_ulong
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
	long long		tt_llong;
	unsigned long	tt_ulong;
	void			*tt_pointer;// check if its in use
	int				tt_int;
	unsigned int	tt_uint;
	unsigned int	tt_zero;
	int				tt_alignleft;
	unsigned int	tt_precision;
	unsigned int	tt_width;
	int				tt_read_width;
	int				tt_read_precision;
	int				tt_baseto;
	int				tt_ucase;
	int				tt_putvar;
} t_typetable;

t_typetable		*g_tt;
int				ft_printf(const char *a, ...);
void			init_typetable(void);
void			reset_typetable(void);
void			print_typetable(void);
int				maketable(char *s);

#endif
