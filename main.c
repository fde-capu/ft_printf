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
int	n1, n2;

void	check_ttable(void)
{
	ft_putstr("|a:");
	ft_putstr(ft_itoa(g_f->a));
	ft_putstr("|z:");
	ft_putstr(ft_itoa(g_f->z));
	ft_putstr("|w:");
	ft_putstr(ft_itoa(g_f->w));
	ft_putstr(":");
	ft_putstr(ft_itoa(g_f->wd));
	ft_putstr("|p:");
	ft_putstr(ft_itoa(g_f->p));
	ft_putstr(":");
	ft_putstr(ft_itoa(g_f->pd));
	ft_putstr("-");
	ft_putstr(ft_itoa(g_f->pn));
	ft_putstr("|t:");
	ft_putstr(&g_f->t);
	ft_putstr("|\t");
}

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
	n1 = ft_printf(s1, v); check_ttable(); \
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
	n1 = ft_printf(s1, a, v); check_ttable(); \
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
	ft_printf(s1, a, a2, v); check_ttable(); \
	printf(s2, a, a2, v);

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

	V("%0*.*i", -2, -2, 8)
	V("%0*.*i", -2, -1, 8)
	V("%0*.*i", 1, -2, 8)
	V("%0*.*i", 2, -2, 8)
	V("%0*.*i", 2, -1, 8)
	V("%0*.*i", 1, 0, 0)
	V("%0*.*i", 2, 0, 8)
	V("%0*.*d", 4, -1, -12)

	V("%*.*i", 2, -2, 8)
	V("%*.*i", -2, -2, 8)
	V("%*.*i", -2, 2, 8)
	V("%*.*i", 1, -2, 8)
	V("%*.*i", -2, 3, 8)
	V("%*.*i", 0, -2, 8)
	V("%*.*i", 0, 2, 8)
	V("%*.*d", 19, -14, -42)
	
	S("%.s", "-a")
	S("%1.s", "-a")

	S1("%.*s", 0, "abcdefhijklmnop")
	S1("%.*s", 3, "abcdefhijklmnop")
	S1("%.*s", 2, "0")
	S1("%.*s", 3, "-a")

	S2("%*.*s", -2, -2, "abcdefghijklmnop")
	S2("%*.*s", 0, -2, "abcdefghijklmnop")

	S("%x", 0)
	S("%X", 0)

int a = 12;

	ft_printf("50?\n");
	ft_printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0); printf("\n");
	   printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	fflush(stdout);
	ft_putnbr_fd( \
		ft_printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0) \
	, 1);	printf("\n");
	ft_putnbr_fd( \
		printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0) \
	, 1);	printf("\n");

// 509 
	a = 12;
	ft_printf("509\n");
	ft_printf("_%*i_, _%*d_, _%*d_, _%*d_, _%*d_, _%*d_, _%*u_, _%*x_, _%*X_", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0); printf("\n");
       printf("_%*i_, _%*d_, _%*d_, _%*d_, _%*d_, _%*d_, _%*u_, _%*x_, _%*X_", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0);
	fflush(stdout);	printf("\n\n");
	S1("%*i", a, 0) S1("%*d", a, 0) S1("%*d", a, 0) S1("%*d", a, 0) S1("%*d", a, 0) S1("%*d", a, 0) 	S1("%*u", a, 0)	S1("%*x", a, 0)	S1("%*x", a, 0)
	printf("\n");
	ft_putnbr_fd( \
		ft_printf("_%*i_, _%*d_, _%*d_, _%*d_, _%*d_, _%*d_, _%*u_, _%*x_, _%*X_", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0) \
	, 1);	printf("\n");
	ft_putnbr_fd( \
		printf("_%*i_, _%*d_, _%*d_, _%*d_, _%*d_, _%*d_, _%*u_, _%*x_, _%*X_", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0) \
	, 1);	printf("\n");

//511
	ft_printf("511\n");
	ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL); printf("\n"); // 512?
	   printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL); // 512?
	fflush(stdout);	printf("\n\n");
	S("%-2s", NULL);
	ft_putnbr_fd( \
		ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL) \
	, 1);	printf("\n");
	ft_putnbr_fd( \
		printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL) \
	, 1);	printf("\n");


	S("%d", "(null)")
	S("%d", "")

	printf("\n\n");
	
	//char	c = 'a';
	//int		d = 2147483647;
	//int		e = -2147483648;
	//int		f = 42;
	//int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	//int		k = 123456789;
	int		l = 0;
	//int		m = -12345678;
	//char	*n = "abcdefghijklmnop";
	//char	*o = "-a";
	char	*p = "-12";
	//char	*q = "0";
	char	*r = "%%";
	//char	*s = "-2147483648";
	//char	*t = "0x12345678";
	//char	*u = "-0";

a = 12;

n1 = \
	 ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l);
printf("\n");
n2 = \
	 printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l);
printf("\n U %d:%d S \n\n", n1, n2);



n1 = \
	 ft_printf( \
		"%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j \
	);
printf("\n");
n2 = \
	 printf( \
		"%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j \
	);
printf("\n U %d:%d S \n\n", n1, n2);


n1 = \
	 ft_printf( \
		"%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i \
	);
printf("\n");
n2 = \
	 printf( \
		"%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i \
	);
printf("\n U %d:%d S \n\n", n1, n2);



n1 = \
	 ft_printf( \
		"%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i \
	);
printf("\n");
n2 = \
	 printf( \
		"%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i \
	);
printf("\n U %d:%d S \n\n", n1, n2);


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






	return (0);

}
