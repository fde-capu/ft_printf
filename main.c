/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200211120024 ||:|||                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"

int	main()
{
	int	x = 42;
	int	*z;

	z = &x;

	printf("\n\n");fflush(stdout);
	printf	("System || User\n");fflush(stdout);
	printf("\n");

	printf	 ("S %%%% _%%_\n");fflush(stdout);
	ft_printf("U %%%% _%%_\n");
	printf("\n");
	
	printf	 ("S %%c _%c_\n", 'X');fflush(stdout);
	ft_printf("U %%c _%c_\n", 'X');
	printf("\n");

	printf	 ("S %%5c _%5c_\n", 'X');fflush(stdout);
	ft_printf("U %%5c _%5c_\n", 'X');
	printf("\n");

//	printf	 ("S 05c_%05c_\n", 'X');fflush(stdout);
	// this below should not work (throw error)
	printf	 ("S %%05c _(error)_\n");fflush(stdout);
	ft_printf("U %%05c _%05c_\n", 'X');
	printf("\n");

	printf	 ("S %%p _%p_\n", z);fflush(stdout);
	ft_printf("U %%p _%p_\n", z);
	printf("\n");
	
	printf	 ("S %%d _%d_\n", 123);fflush(stdout);
	ft_printf("U %%d _%d_\n", 123);
	printf("\n");
	
	printf	 ("S %%0d _%0d_\n", 6);fflush(stdout);
	ft_printf("U %%0d _%0d_\n", 6);
	printf("\n");
	
//	printf	 ("S %%00d_%00d_\n", 6);fflush(stdout);
	printf	 ("S %%00d _(error)_\n");fflush(stdout);
	ft_printf("U %%00d _%00d_\n", 6);
	printf("\n");
	
	printf	 ("S %%06d _%06d_\n", 6);fflush(stdout);
	ft_printf("U %%06d _%06d_\n", 6);
	printf("\n");
	
	printf	 ("S %%6d _%6d_\n", 6);fflush(stdout);
	ft_printf("U %%6d _%6d_\n", 6);
	printf("\n");
	
	printf	 ("S %%-6d _%-6d_\n", 6);fflush(stdout);
	ft_printf("U %%-6d _%-6d_\n", 6);
	printf("\n");
	
	//printf	 ("S %%-06d_%-06d_\n", 6);fflush(stdout);
	printf	 ("S %%-06d _(error)_\n");fflush(stdout);
	ft_printf("U %%-06d _%-06d_\n", 6);
	printf("\n");
	
	printf	 ("S %%-10d _%-10d_\n", -6);fflush(stdout);
	ft_printf("U %%-10d _%-10d_\n", -6);
	printf("\n");
	
	printf	 ("S %%10d _%10d_\n", -6);fflush(stdout);
	ft_printf("U %%10d _%10d_\n", -6);
	printf("\n");
	
	//printf	 ("S %%-010d_%-010d_\n", -6);fflush(stdout);
	printf	 ("S %%-010d _(error)_\n");fflush(stdout);
	ft_printf("U %%-010d _%-010d_\n", -6);
	printf("\n");
	
	printf	 ("S %%010d _%010d_\n", -6);fflush(stdout);
	ft_printf("U %%010d _%010d_\n", -6);
	printf("\n");
	
	printf	 ("S %%.5d _%.5d_\n", 6);fflush(stdout);
	ft_printf("U %%.5d _%.5d_\n", 6);
	printf("\n");
	
	printf	 ("S %%.5d _%.5d_\n", -123);fflush(stdout);
	ft_printf("U %%.5d _%.5d_\n", -123);
	printf("\n");
	
	printf	 ("S %%10.5d _%.5d_\n", 6);fflush(stdout);
	ft_printf("U %%10.5d _%.5d_\n", 6);
	printf("\n");
	
	printf	 ("S %%10.5d _%.5d_\n", -123);fflush(stdout);
	ft_printf("U %%10.5d _%.5d_\n", -123);
	printf("\n");
	
	printf	 ("S %%i _%i_\n", 123);fflush(stdout);
	ft_printf("U %%i _%i_\n", 123);
	printf("\n");
	
	printf	 ("S %%u _%u_\n", -123);fflush(stdout);
	ft_printf("U %%u _%u_\n", -123);
	printf("\n");
	
	printf	 ("S %%x _%x_\n", 123);fflush(stdout);
	ft_printf("U %%x _%x_\n", 123);
	printf("\n");
	
	printf	 ("S %%X _%X_\n", 123);fflush(stdout);
	ft_printf("U %%X _%X_\n", 123);
	printf("\n\n");fflush(stdout);

	return (0);
}
