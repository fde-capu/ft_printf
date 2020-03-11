/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200218151612 ||::||                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"
#include <math.h>
#include <limits.h>
#include <stdint.h>
# include <stdio.h> 

char *s1, *s2;
int	n1, n2;

void	check_ttable(t_ttable *t)
{
	ft_putstr("\t\t|a:");
	ft_putstr(ft_itoa(t->a));
	ft_putstr("|z:");
	ft_putstr(ft_itoa(t->z));
	ft_putstr("|w:");
	ft_putstr(ft_itoa(t->w));
	ft_putstr(":");
	ft_putstr(ft_itoa(t->wd));
	ft_putstr("|p:");
	ft_putstr(ft_itoa(t->p));
	ft_putstr(":");
	ft_putstr(ft_itoa(t->pd));
	ft_putstr("-");
	ft_putstr(ft_itoa(t->pn));
	ft_putstr("|t:");
	ft_putstr(&t->t);
	ft_putstr("|c");
	ft_putstr(ft_itoa(t->c));
	ft_putstr("|\"");
	ft_putstr(t->s);
	ft_putstr("\"");
	//ft_putstr("|\n");
}

#define S0(s) \
	s1 = ft_strcat("U \"", s); \
	s1 = ft_strcat(s1, "\" _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("S \"", s); \
	s2 = ft_strcat(s2, "\" _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\t"); \
	n1 = ft_printf(s1); check_ttable(gg); \
	printf("\n"); \
	n2 = printf(s2); fflush(stdout); \
	printf("U %d|%d S\n\n", n1, n2);

#define SC(s, v) \
	s1 = ft_strcat("U %", s); \
	s1 = ft_strcat(s1, " (\'"); \
	s1 = ft_strcat(s1, ft_chrtostr(v)); \
	s1 = ft_strcat(s1, "\') _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("S %", s); \
	s2 = ft_strcat(s2, " (\'"); \
	s2 = ft_strcat(s2, ft_chrtostr(v)); \
	s2 = ft_strcat(s2, "\') _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\t"); \
	n1 = ft_printf(s1, v); check_ttable(gg); \
	printf("\n"); \
	n2 = printf(s2, v); fflush(stdout); \
	printf("U %d|%d S\n\n", n1, n2);

#define S(s, v) \
	s1 = ft_strcat("U %", s); \
	s1 = ft_strcat(s1, " (\""); \
	s1 = ft_strcat(s1, v); \
	s1 = ft_strcat(s1, "\") _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("S %", s); \
	s2 = ft_strcat(s2, " (\""); \
	s2 = ft_strcat(s2, v); \
	s2 = ft_strcat(s2, "\") _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\t"); \
	n1 = ft_printf(s1, v); check_ttable(gg); \
	printf("\n"); \
	n2 = printf(s2, v); fflush(stdout); \
	printf("U %d|%d S\n\n", n1, n2);

#define S1(s, a, v) \
	s1 = ft_strcat("U %", s); \
	s1 = ft_strcat(s1, " (\""); \
	s1 = ft_strcat(s1, v); \
	s1 = ft_strcat(s1, "\","); \
	s1 = ft_strcat(s1, ft_itoa(a)); \
	s1 = ft_strcat(s1, ") _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("S %", s); \
	s2 = ft_strcat(s2, " (\""); \
	s2 = ft_strcat(s2, v); \
	s2 = ft_strcat(s2, "\","); \
	s2 = ft_strcat(s2, ft_itoa(a)); \
	s2 = ft_strcat(s2, ") _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\t"); \
	n1 = ft_printf(s1, a, v); check_ttable(gg); \
	printf("\n"); \
	n2 = printf(s2, a, v); fflush(stdout); \
	printf("U %d|%d S\n\n", n1, n2);

#define S2(s, a, a2, v) \
	s1 = ft_strcat("U %", s); \
	s1 = ft_strcat(s1, " (\""); \
	s1 = ft_strcat(s1, v); \
	s1 = ft_strcat(s1, "\","); \
	s1 = ft_strcat(s1, ft_itoa(a)); \
	s1 = ft_strcat(s1, ","); \
	s1 = ft_strcat(s1, ft_itoa(a2)); \
	s1 = ft_strcat(s1, ") _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("\nS %", s); \
	s2 = ft_strcat(s2, " (\""); \
	s2 = ft_strcat(s2, v); \
	s2 = ft_strcat(s2, "\","); \
	s2 = ft_strcat(s2, ft_itoa(a)); \
	s2 = ft_strcat(s2, ","); \
	s2 = ft_strcat(s2, ft_itoa(a2)); \
	s2 = ft_strcat(s2, ") _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\n\n"); \
	ft_printf(s1, a, a2, v); check_ttable(gg); \
	printf(s2, a, a2, v);

#define T(s, v) \
	s1 = ft_strcat("U %", s); \
	s1 = ft_strcat(s1, " ("); \
	s1 = ft_strcat(s1, ft_itoa(v)); \
	s1 = ft_strcat(s1, ") _"); \
	s1 = ft_strcat(s1, s); \
	s1 = ft_strcat(s1, "_\t"); \
	s2 = ft_strcat("S %", s); \
	s2 = ft_strcat(s2, " ("); \
	s2 = ft_strcat(s2, ft_itoa(v)); \
	s2 = ft_strcat(s2, ") _"); \
	s2 = ft_strcat(s2, s); \
	s2 = ft_strcat(s2, "_\t"); \
	n1 = ft_printf(s1, v); check_ttable(gg); \
	printf("\n"); \
	n2 = printf(s2, v); fflush(stdout); \
	printf("U %d|%d S\n\n", n1, n2);

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
	ft_printf(s1, v1, v2, v3); check_ttable(gg); \
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
	ft_printf(s1, v1, v2); check_ttable(gg); \
	printf(s2, v1, v2);

int	main()
{
	int	x = 42;
	//int	*z;
	//z = &x;
	//unsigned int	*avar;
	//unsigned int	thevar;
	//avar = &thevar;
	//*avar = 42;

	printf("\n\n");
	printf	("DEBUG\n\n");

	//ft_printf("");
	//S0("")
	//S0("__")
	//S0("123")

//	S0("")
//	S0("Teste")
//	S0("%%")
//	S("%s", "Flávio")
//	SC("%c", 'X')
//	T("%i", 42);
//	T("%0i", 42);
//	T("%-0i", 42);
//	T("%p", x);
//	T("%p", &x);
//	printf("--%p--\n", x);
//	printf("--%p--\n", &x);
//	ft_printf("--%p--\n", x);
//	ft_printf("--%p--\n", &x);

//510
	ft_printf("510\n");
	ft_printf("_%c_, _%-c_, _%12c_, _%-3c_, _%-1c_, _%1c_, _%-2c_, _%-4c_, _%5c_, _%3c_, _%-*c_, _%-*c_, _%*c_, _%*c_", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0); printf("\n"); // 511
       printf("_%c_, _%-c_, _%12c_, _%-3c_, _%-1c_, _%1c_, _%-2c_, _%-4c_, _%5c_, _%3c_, _%-*c_, _%-*c_, _%*c_, _%*c_", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0); // 511
	printf("\n\n");
//	S("%c", 0) S("%-c", 0) S("%12c", 0) S("%-3c", 0) S("%-1c", 0) S("%1c", 0) S("%-2c", 0) S("%-4c", 0) S("%5c", 0) S("%3c", 0) S1("%*c", -1, 0) S1("%-*c", 0, 0) S1("%*c", 0, 0) S1("%*c", 0, 0)

n1 = \
	 ft_printf( \
		"%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0 \
	);
printf("\n");
n2 = \
	 printf( \
		"%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0 \
	);
printf("\n U %d:%d S \n\n", n1, n2);

	SC("%c", 0);
	SC("%-c", 0);
	SC("%12c", 0);
	return (0);

}

// S (s, v)
// S0 (s)
// SC (s, c)
// T (s, i)
// S1 (s, i, v)
// S2 (s, i, i, v)
// V (s, i, i, i)
// X (s, i, i)
