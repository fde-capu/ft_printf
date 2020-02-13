/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200213012040 ||::||                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"

int	main()
{
	int	x = 42;
	int	*z;
	z = &x;

	printf("\n\n");
	printf	("System || User\n\n");
	printf("basics:\n");

	printf	 ("\tS %%%% _%%_\t");
	printf	 ("\tS %%c _%c_\t", 'X');
	printf	 ("\tS %%5c _%5c_\t", 'X');
	printf	 ("\tS %%0d _%0d_\t", 6);
	printf	 ("\tS %%00d _err_\t");
	printf	 ("\tS %%p _%p_\t", z);
	printf("\n");
	ft_printf("\tU %%%% _%%_\t");
	ft_printf("\tU %%c _%c_\t", 'X');
	ft_printf("\tU %%5c _%5c_\t", 'X');
	ft_printf("\tU %%0d _%0d_\t", 6);
	ft_printf("\tU %%00d _%00d_\t", 6);
	ft_printf("\tS %%p _%p_\t", z);
	
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
	
	printf	 ("\tS %%i _%i_\t", 123);
	printf	 ("\tS %%u _%u_\t", -123);
	printf	 ("\tS %%X _%X_\t", 123);
	printf	 ("\tS %%x _%x_\t", 123);
	printf("\n");
	ft_printf("\tU %%i _%i_\t", 123);
	ft_printf("\tU %%u _%u_\t", -123);
	ft_printf("\tU %%X _%X_\t", 123);
	ft_printf("\tU %%x _%x_\t", 123);
	printf("\n\n");

	return (0);
}
