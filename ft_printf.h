/* ******************************************* */
/*                                             */
/*                     ||||::::::||||:|||::||| */
/* ft_printf.h         :|::::|:::||:::|:||::|: */
/*                     :||:||:|:|::|:|:||||||: */
/*     |:|::| <|:|::|>                         */
/*                                             */
/* C20200207142351 |:|::|                      */
/* U20200214083041 :|:||:                      */
/*                                             */
/* ******************************************* */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> // REM
# define FDOUT 1
# define ERRORMSG "^~~~ format error\n"
# define TTS g_tt->tt_string
# define TTI g_tt->tt_int
# define TTU g_tt->tt_uint
# define TTL g_tt->tt_long
# define TTZ g_tt->tt_zero
# define TTW g_tt->tt_width
# define TRW g_tt->tt_read_width
# define TTP g_tt->tt_precision
# define TRP g_tt->tt_read_precision
# define TPT g_tt->tt_pointer
# define TTC g_tt->tt_char
# define TAL g_tt->tt_alignleft
# define TGC g_tt->tt_getchar
# define TGS g_tt->tt_getstring
# define TGP g_tt->tt_getpointer
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
