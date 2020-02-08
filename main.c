/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200208193713 ||||:|                      */
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
	printf	 ("S _%%_\n");fflush(stdout);
	ft_printf("U _%%_\n");
	printf	 ("S c_%c_\n", 'X');fflush(stdout);
	ft_printf("U c_%c_\n", 'X');
	printf	 ("S p_%p_\n", z);fflush(stdout);
	ft_printf("U p_%p_\n", z);
	printf	 ("S d_%d_\n", 123);fflush(stdout);
	ft_printf("U d_%d_\n", 123);
	printf	 ("S i_%i_\n", 123);fflush(stdout);
	ft_printf("U i_%i_\n", 123);
	printf	 ("S u_%u_\n", -123);fflush(stdout);
	ft_printf("U u_%u_\n", -123);
	printf	 ("S x_%x_\n", 123);fflush(stdout);
	ft_printf("U x_%x_\n", 123);
	printf	 ("S X_%X_\n", 123);fflush(stdout);
	ft_printf("U X_%X_\n", 123);
	printf("\n\n");fflush(stdout);

	return (0);
}
