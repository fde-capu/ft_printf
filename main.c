/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200207141603 |::||:                      */
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
	char	o = 'X';
	char	*d;
	d = &o;
	ft_printf("p: %p\n", d);
	printf("sys p: %p\n", d);
//	printf("(sys) 1: %, 2: %%, 3: %%% \n", -100);
//	Original printf allways whines after %.
	unsigned char	a = 0x64;
	int				b = 0xFAFA;

	printf("sys a: %X [%x]\n",a,a);
	printf("sys b: %X [%x]\n",b,b);
	ft_printf("ft_ a: %X [%x]\n",a,a);
	ft_printf("ft_ b: %X [%x]\n",b,b);
	return (0);
}
