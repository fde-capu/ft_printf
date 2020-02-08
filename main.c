/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200208191348 ||:::|                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"

int	main()
{
	int	x = 42;
	int	*z;

	z = &x;

	printf("\n\n");
	printf	("System || User\n");
	printf	 ("S _%%_\n");
	ft_printf("U _%%_\n");
	printf	 ("S c_%c_\n", 'X');
	ft_printf("U c_%c_\n", 'X');
	printf	 ("S p_%p_\n", z);
	ft_printf("U p_%p_\n", z);
	printf	 ("S d_%d_\n", 123);
	ft_printf("U d_%d_\n", 123);
	printf	 ("S i_%i_\n", 123);
	ft_printf("U i_%i_\n", 123);
	printf	 ("S u_%u_\n", -123);
	ft_printf("U u_%u_\n", -123);
	printf	 ("S x_%x_\n", 123);
	ft_printf("U x_%x_\n", 123);
	printf	 ("S X_%X_\n", 123);
	ft_printf("U X_%X_\n", 123);
	printf("\n\n");

	return (0);
}
