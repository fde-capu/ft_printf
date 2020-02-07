/* ******************************************* */
/*                                             */
/*                     ||||::::::||||:|||::||| */
/* ft_printf.h         :|::::|:::||:::|:||::|: */
/*                     :||:||:|:|::|:|:||||||: */
/*     |:|::| <|:|::|>                         */
/*                                             */
/* C20200207142351 |:|::|                      */
/* U20200207183843 ||::||                      */
/*                                             */
/* ******************************************* */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> // REM
# define FDOUT 1
# define ERRORMSG "^~~~ format error\n"

typedef struct s_typetable
{
	char	tt_char;
	char	*tt_string;
	void	*tt_pointer;
} t_typetable;

t_typetable		*tt;
int				ft_printf(const char *a, ...);
void			init_typetable(void);
void			reset_typetable(void);
void			print_typetable(void);
int				joker(char *s);

#endif
