/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200211094803 ::|::|                      */
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

	printf	 ("S %%%%_%%_\n");fflush(stdout);
	ft_printf("U %%%%_%%_\n");
	printf("\n");
	
	printf	 ("S %%c_%c_\n", 'X');fflush(stdout);
	ft_printf("U %%c_%c_\n", 'X');
	printf("\n");

	printf	 ("S %%5c_%5c_\n", 'X');fflush(stdout);
	ft_printf("U %%5c_%5c_\n", 'X');
	printf("\n");

//	printf	 ("S 05c_%05c_\n", 'X');fflush(stdout);
	// this below should not work (throw error)
	printf	 ("S %%05c_(error)_\n");fflush(stdout);
	ft_printf("U %%05c_%05c_\n", 'X');
	printf("\n");

	printf	 ("S %%p_%p_\n", z);fflush(stdout);
	ft_printf("U %%p_%p_\n", z);
	printf("\n");
	
	printf	 ("S %%d_%d_\n", 123);fflush(stdout);
	ft_printf("U %%d_%d_\n", 123);
	printf("\n");
	
	printf	 ("S %%0d_%0d_\n", 6);fflush(stdout);
	ft_printf("U %%0d_%0d_\n", 6);
	printf("\n");
	
//	printf	 ("S %%00d_%00d_\n", 6);fflush(stdout);
	printf	 ("S %%00d_(error)_\n");fflush(stdout);
	ft_printf("U %%00d_%00d_\n", 6);
	printf("\n");
	
	printf	 ("S %%06d_%06d_\n", 6);fflush(stdout);
	ft_printf("U %%06d_%06d_\n", 6);
	printf("\n");
	
	printf	 ("S %%6d_%6d_\n", 6);fflush(stdout);
	ft_printf("U %%6d_%6d_\n", 6);
	printf("\n");
	
	printf	 ("S %%-6d_%-6d_\n", 6);fflush(stdout);
	ft_printf("U %%-6d_%-6d_\n", 6);
	printf("\n");
	
	printf	 ("S %%i_%i_\n", 123);fflush(stdout);
	ft_printf("U %%i_%i_\n", 123);
	printf("\n");
	
	printf	 ("S %%u_%u_\n", -123);fflush(stdout);
	ft_printf("U %%u_%u_\n", -123);
	printf("\n");
	
	printf	 ("S %%x_%x_\n", 123);fflush(stdout);
	ft_printf("U %%x_%x_\n", 123);
	printf("\n");
	
	printf	 ("S %%X_%X_\n", 123);fflush(stdout);
	ft_printf("U %%X_%X_\n", 123);
	printf("\n\n");fflush(stdout);

	return (0);
}
