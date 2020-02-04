/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200204002018 ||||||                      */
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
	return (0);
}
