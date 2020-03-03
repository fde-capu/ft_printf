/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200218122926 ||:|::                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"
#include <math.h>
#include <limits.h>
#include <stdint.h>
# include <stdio.h> 

#define T(s, v) \
	char	*s1 = ft_strcat("U _", s); \
	s1 = ft_strcat(s1, "_\t"); \
	char	*s2 = ft_strcat("\nS _", s); \
	s2 = ft_strcat(s2, "_\n\n"); \
	ft_printf(s1, v); check_ttable(); \
	printf(s2, v);

int	main()
{
	int	x = 42;
	int	*z;
	z = &x;
	unsigned int	*avar;
	unsigned int	thevar;
	avar = &thevar;
	*avar = 42;

	printf("\n\n");
	printf	("DEBUG\n\n");

	T("%d", 42)

	printf("\n\n");


	return (0);
}
