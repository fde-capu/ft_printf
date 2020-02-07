/* ******************************************* */
/*                                             */
/*                     ||||::::::||||:|||::||| */
/* ft_printf.h         :|::::|:::||:::|:||::|: */
/*                     :||:||:|:|::|:|:||||||: */
/*     |:|::| <|:|::|>                         */
/*                                             */
/* C20200207142351 |:|::|                      */
/* U20200207142352 |:|:||                      */
/*                                             */
/* ******************************************* */

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
