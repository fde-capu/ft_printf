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

int	main()
{
	int	x = 42;
	int	*z;
	z = &x;

	printf("\n\n");
	printf	("System || User\n\n");
	printf("basics:\n");

	printf	 ("\tS %%%% _%%_\t");
	printf	 ("\tS %%d _%d_\t", 42);
	printf	 ("\tS %%c _%c_\t", 'X');
	printf	 ("\tS %%5c _%5c_\t", 'X');
	printf	 ("\tS %%0d _%0d_\t", 6);
	printf	 ("\tS %%00d _err_\t");
	printf	 ("\tS %%p _%p_\t", z);
	printf	 ("\tS %%s _%s_\t", "Hey, ho!");
	printf("\n");
	ft_printf("\tU %%%% _%%_\t");
	ft_printf("\tS %%d _%d_\t", 42);
	ft_printf("\tU %%c _%c_\t", 'X');
	ft_printf("\tU %%5c _%5c_\t", 'X');
	ft_printf("\tU %%0d _%0d_\t", 6);
	ft_printf("\tU %%00d _%00d_\t", 6);
	ft_printf("\tS %%p _%p_\t", z);
	ft_printf("\tS %%s _%s_\t", "Hey, ho!");
	
	printf("\n");
	printf("\ninput variants:");
	printf("\n");

	printf	 ("\tS %%d (hex) _%d_\t", 0x2a);
	printf	 ("\tS %%d (HEX) _%d_\t", 0x2A);
	printf	 ("\tS %%d (oct) _%d_\t", 012);
	printf	 ("\tS %%i (hex) _%i_\t", 0x2a);
	printf	 ("\tS %%i (HEX) _%i_\t", 0x2A);
	printf	 ("\tS %%i (oct) _%i_\t", 012);
	printf("\n");
	ft_printf	 ("\tU %%d (hex) _%d_\t", 0x2a);
	ft_printf	 ("\tU %%d (HEX) _%d_\t", 0x2A);
	ft_printf	 ("\tU %%d (oct) _%d_\t", 012);
	ft_printf	 ("\tU %%i (hex) _%i_\t", 0x2a);
	ft_printf	 ("\tU %%i (HEX) _%i_\t", 0x2A);
	ft_printf	 ("\tU %%i (oct) _%i_\t", 012);

	printf("\n");
	printf("\nwidth:");
	printf("\n");

	printf	 ("S %%06d _%06d_\t", 6);
	printf	 ("S %%6d _%6d_\t", 6);
	printf	 ("S %%-6d _%-6d_\t", 6);
	printf	 ("S %%-06d _(error)_\t");
	printf	 ("S %%-10d _%-10d_\t", -6);
	printf	 ("S %%10d _%10d_\t", -6);
	printf	 ("S %%-010d _(error)_\t");
	printf	 ("S %%010d _%010d_\t", -6);
	printf("\n");
	ft_printf("U %%06d _%06d_\t", 6);
	ft_printf("U %%6d _%6d_\t", 6);
	ft_printf("U %%-6d _%-6d_\t", 6);
	ft_printf("U %%-06d _%-06d_\t", 6);
	ft_printf("U %%-10d _%-10d_\t", -6);
	ft_printf("U %%10d _%10d_\t", -6);
	ft_printf("U %%-010d _%-010d_\t", -6);
	ft_printf("U %%010d _%010d_\t", -6);

	printf("\n");
	printf("\nwidth read:");
	printf("\n");
	printf	 ("S %%0*d _err_\t");
	printf	 ("S %%*d _%*d_\t", 6, 6);
	printf	 ("S %%-*d _%-*d_\t", 6, 6);
	printf	 ("S %%-0*d _err_\t\t");
	printf	 ("S %%-*d _%-*d_\t", 10, -6);
	printf	 ("S %%*d _%*d_\t", 10, -6);
	printf	 ("S %%-0*d _err_\t\t");
	printf	 ("S %%0*d _%0*d_\t", 10, -6);
	printf("\n");
	ft_printf("U %%0*d _%0*d_\t", 6, 6);
	ft_printf("U %%*d _%*d_\t", 6, 6);
	ft_printf("U %%-*d _%-*d_\t", 6, 6);
	ft_printf("U %%-0*d _%-0*d_\t", 6, 6);
	ft_printf("U %%-*d _%-*d_\t", 10, -6);
	ft_printf("U %%*d _%*d_\t", 10, -6);
	ft_printf("U %%-0*d _%-0*d_\t", 10, -6);
	ft_printf("U %%0*d _%0*d_\t", 10, -6);

	printf("\n");
	printf("\nprecision:");
	printf("\n");
	printf	 ("\tS %%.5d _%.5d_\t", 6);
	printf	 ("\tS %%.5d _%.5d_\t", -123);
	printf	 ("\tS %%01.5d _error_\t");
	printf	 ("\tS %%10.5d _%10.5d_\t", 6);
	printf	 ("\tS %%10.5d _%10.5d_\t", -123);
	printf("\n");
	ft_printf("\tU %%.5d _%.5d_\t", 6);
	ft_printf("\tU %%.5d _%.5d_\t", -123);
	ft_printf("\tU %%01.5d _%01.5d_\t", 6);
	ft_printf("\tU %%10.5d _%10.5d_\t", 6);
	ft_printf("\tU %%10.5d _%10.5d_\t", -123);
	
	printf("\n");
	printf("\nprecision read:");
	printf("\n");
	printf	 ("\tS %%.*d _%.*d_\t", 5, 6);
	printf	 ("\tS %%.*d _%.*d_\t", 5, -123);
	printf	 ("\tS %%10.*d _%10.*d_\t", 5, 6);
	printf	 ("\tS %%10.*d _%10.*d_\t", 5, -123);
	printf("\n");
	ft_printf("\tU %%.*d _%.*d_\t", 5, 6);
	ft_printf("\tU %%.*d _%.*d_\t", 5, -123);
	ft_printf("\tU %%10.*d _%10.*d_\t", 5, 6);
	ft_printf("\tU %%10.*d _%10.*d_\t", 5, -123);

	printf("\n");
	printf("\nwidth and precision:");
	printf("\n");
	printf	 ("\tS %%7.5d _%7.5d_\t", 6);
	printf	 ("\tS %%3.5d _%3.5d_\t", -123);
	printf	 ("\tS %%10.5d _%10.5d_\t", 6);
	printf	 ("\tS %%10.5d _%10.5d_\t", -123);
	printf("\n");
	ft_printf("\tU %%7.5d _%7.5d_\t", 6);
	ft_printf("\tU %%3.5d _%3.5d_\t", -123);
	ft_printf("\tU %%10.5d _%10.5d_\t", 6);
	ft_printf("\tU %%10.5d _%10.5d_\t", -123);
	
	printf("\n");
	printf("\nwidth and precision read:");
	printf("\n");
	printf	 ("\tS %%*.*d _%*.*d_\t", 7, 5, 6);
	printf	 ("\tS %%*.*d _%*.*d_\t", 3, 5, -123);
	printf	 ("\tS %%*.*d _%*.*d_\t", 10, 5, 6);
	printf	 ("\tS %%*.*d _%*.*d_\t", 10, 5, -123);
	printf("\n");
	ft_printf("\tU %%*.*d _%*.*d_\t", 7, 5, 6);
	ft_printf("\tU %%*.*d _%*.*d_\t", 3, 5, -123);
	ft_printf("\tU %%*.*d _%*.*d_\t", 10, 5, 6);
	ft_printf("\tU %%*.*d _%*.*d_\t", 10, 5, -123);

	printf("\n");
	ft_printf("\nhex:");
	printf("\n");
	printf	 ("\tS %%i(123) _%i_\t", 123);
	printf	 ("\tS %%i(0x123) _%i_\t", 0x123);
	printf	 ("\tS %%i(0X123) _%i_\t", 0x123);
	printf	 ("\tS %%i(0123) _%i_\t", 0123);
	printf	 ("\tS %%u _%u_\t", -123);
	printf	 ("\tS %%X _%X_\t", 123);
	printf	 ("\tS %%x _%x_\t", -123);
	printf("\n");
	ft_printf("\tU %%i(123) _%i_\t", 123);
	ft_printf ("\tU %%i(0x123) _%i_\t", 0x123);
	ft_printf ("\tU %%i(0X123) _%i_\t", 0x123);
	ft_printf ("\tU %%i(0123) _%i_\t", 0123);
	ft_printf("\tU %%u _%u_\t", -123);
	ft_printf("\tU %%X _%X_\t", 123);
	ft_printf("\tU %%x _%x_\t", -123);

	unsigned int	*avar;
	unsigned int	thevar;
	avar = &thevar;
	*avar = 42;

	printf("\n");
	ft_printf("\nBONUS:");
	printf("\n");
	printf("S This var %d...%n(%%n, 16)", *avar, avar);
	printf("...is now %d.\t", *avar);
	printf("\n");


	*avar = 42;
	ft_printf("U This var %d...%n(%%n, 16)", *avar, avar);
	ft_printf("...is now %d.\t", *avar);
	
	printf("\n");
	ft_printf("\nlong:");
	printf("\n");
	printf("S %%ld _%ld_\t", LONG_MAX - 123);
	printf("%%li _%li_\t", LONG_MIN + 123);
	printf("%%lu _%lu_\t", ULONG_MAX - 123);
	printf("%%lld _%lld_\t", LLONG_MIN + 123);
	printf("%%lli _%lli_\t", LLONG_MAX - 123);
	printf("%%llu _%llu_\t", ULLONG_MAX - 123);
	printf("\n");
	ft_printf("U %%ld _%ld_\t", LONG_MAX - 123);
	ft_printf("%%li _%li_\t", LONG_MIN + 123);
	ft_printf("%%lu _%lu_\t", ULONG_MAX - 123);
	ft_printf("%%lld _%lld_\t", LLONG_MIN + 123);
	ft_printf("%%lli _%lli_\t", LLONG_MAX - 123);
	ft_printf("%%llu _%llu_\t", ULLONG_MAX - 123);

	printf("\n");
	ft_printf("\nlong extremes:");
	printf("\n");
	printf("S %%ld _%ld_\t", LONG_MAX);
	printf("%%li _%li_\t", LONG_MIN);
	printf("%%lu _%lu_\t", ULONG_MAX);
	printf("%%lld _%lld_\t", LLONG_MIN);
	printf("%%lli _%lli_\t", LLONG_MAX);
	printf("%%llu _%llu_\t", ULLONG_MAX);
	printf("\n");
//	ft_printf("U %%ld _%ld_\t", LONG_MAX);
//	ft_printf("%%li _%li_\t", LONG_MIN);
//	ft_printf("%%lu _%lu_\t", ULONG_MAX);
//	ft_printf("%%lld _%lld_\t", LLONG_MIN);
//	ft_printf("%%lli _%lli_\t", LLONG_MAX);
//	ft_printf("%%llu _%llu_\t", ULLONG_MAX);

	printf("\n\n");
	return (0);
}
