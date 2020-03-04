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

char *s1, *s2;

#define T(s, v) \
	s1 = ft_strcat("U %", s); \
	s1 = ft_strcat(s1, " ("); \
	s1 = ft_strcat(s1, ft_itoa(v)); \
	s1 = ft_strcat(s1, ") _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("\nS %", s); \
	s2 = ft_strcat(s2, " ("); \
	s2 = ft_strcat(s2, ft_itoa(v)); \
	s2 = ft_strcat(s2, ") _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\n\n"); \
	ft_printf(s1, v); check_ttable(); \
	printf(s2, v);

#define V(s, v1, v2, v3) \
	s1 = ft_strcat("U %", s); \
	s1 = ft_strcat(s1, " ("); \
	s1 = ft_strcat(s1, ft_itoa(v1)); \
	s1 = ft_strcat(s1, ","); \
	s1 = ft_strcat(s1, ft_itoa(v2)); \
	s1 = ft_strcat(s1, ","); \
	s1 = ft_strcat(s1, ft_itoa(v3)); \
	s1 = ft_strcat(s1, ") _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("\nS %", s); \
	s2 = ft_strcat(s2, " ("); \
	s2 = ft_strcat(s2, ft_itoa(v1)); \
	s2 = ft_strcat(s2, ","); \
	s2 = ft_strcat(s2, ft_itoa(v2)); \
	s2 = ft_strcat(s2, ","); \
	s2 = ft_strcat(s2, ft_itoa(v3)); \
	s2 = ft_strcat(s2, ") _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\n\n"); \
	ft_printf(s1, v1, v2, v3); check_ttable(); \
	printf(s2, v1, v2, v3);

#define X(s, v1, v2) \
	s1 = ft_strcat("U %", s); \
	s1 = ft_strcat(s1, " ("); \
	s1 = ft_strcat(s1, ft_itoa(v1)); \
	s1 = ft_strcat(s1, ","); \
	s1 = ft_strcat(s1, ft_itoa(v2)); \
	s1 = ft_strcat(s1, ") _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("\nS %", s); \
	s2 = ft_strcat(s2, " ("); \
	s2 = ft_strcat(s2, ft_itoa(v1)); \
	s2 = ft_strcat(s2, ","); \
	s2 = ft_strcat(s2, ft_itoa(v2)); \
	s2 = ft_strcat(s2, ") _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\n\n"); \
	ft_printf(s1, v1, v2); check_ttable(); \
	printf(s2, v1, v2);

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

	T("%0.d", 0)
	V("%*i", -4, 0, 8)
	V("%.*d", 0, 0, 0) 
	V("%0.i", -4, 0, 8) 
	X("%0*i", 2, 8) 
	X("%.*d", 3, -12) 
	X("%0*d", 3, -12) 
	X("%.*i", -4, 8)
	X("%.*i", 0, 8) 
	X("%.*i", 2, 8) 
	T("%2i", 8)

	V("%*.*i", 2, -2, 8)
	V("%*.*i", 0, -2, 8)
	V("%*.*i", 0, 2, 8)
	V("%*.*i", -2, -2, 8)
	V("%*.*i", -2, 2, 8)
	V("%*.*i", 1, -2, 8)
	V("%*.*i", -2, 3, 8)

	V("%0*.*i", 2, -2, 8)
	V("%0*.*i", 1, -2, 8)
	V("%0*.*i", -2, -2, 8)

	printf("\n\n");

	return (0);
}
