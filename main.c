/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200204005616 |:|||:                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"

int	main()
{
	printf("Hello, you.\n");
	ft_printf("Hello, ft_printf.\n");
	printf   ("Hello, %c printf.\n", 'X');
	ft_printf("Hello, %c ft_printf.\n", 'X');
	ft_printf("Hello, %c ft_printf %s.\n", 'X', "Yes!");
	ft_printf("Some int: %d.\n", 42);
	ft_printf("Some unsigned int: %u.\n", -100);
	ft_printf("1: %, 2: %%, 3: %%% \n", -100);
//	printf("(sys) 1: %, 2: %%, 3: %%% \n", -100);
//	Original printf allways whines after %.
	return (0);
}
