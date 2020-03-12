/* ******************************************* */
/*                                             */
/*                     |:|::|::||:|:::|::::|:| */
/* main.c              :||:||::|:|||:||||::||| */
/*                     :::||::::::||||||:|:|:: */
/*     :::|:| <:::|:|>                         */
/*                                             */
/* C20200203204618 :::|:|                      */
/* U20200218151612 ||::||                      */
/*                                             */
/* ******************************************* */

#include "ft_printf.h"
#include <math.h>
#include <limits.h>
#include <stdint.h>
# include <stdio.h> 
# include <float.h>

#define NL printf("\n");
int	main()
{
	int	x;
	int	*xp;
	int	t;

	NL NL
	x = 42;
	xp = &x;
	t = printf("This is x:%d...", x);
	printf(" (%d) ", t);
	t = printf("Let's change it: %n...", xp);
	printf(" (%d) ", t);
	t = printf("This is x:%d...", x);
	printf(" (%d) ", t);
	NL
	x = 42;
	t = ft_printf("This is x:%d...", x);
	ft_printf(" (%d) ", t);
	t = ft_printf("Let's change it: %n...", xp);
	ft_printf(" (%d) ", t);
	t = ft_printf("This is x:%d...", x);
	ft_printf(" (%d) ", t);
	NL NL

	long l;
	l = LONG_MAX;
	t = printf("This long:%li...", l); 
	printf(" (%d) ", t); NL
	t = printf("This long as int:%i...", l); 
	printf(" (%d) ", t); NL
	t = ft_printf("This long:%li...", l); 
	ft_printf(" (%d) ", t); NL
	t = ft_printf("This long as int:%i...", l); 
	ft_printf(" (%d) ", t); NL

NL NL

	l = LONG_MIN;
	t = printf("This long:%li...", l); 
	printf(" (%d) ", t); NL
	t = printf("This long as int:%i...", l); 
	printf(" (%d) ", t); NL
	t = ft_printf("This long:%li...", l); 
	ft_printf(" (%d) ", t); NL
	t = ft_printf("This long as int:%i...", l); 
	ft_printf(" (%d) ", t); NL

NL NL

	long long ll;
	ll = LLONG_MAX;
	t = printf("This long long:%lli...", ll); 
	printf(" (%d) ", t); NL
	t = printf("This long long as int:%i...", ll); 
	printf(" (%d) ", t); NL
	t = ft_printf("This long long:%lli...", ll); 
	ft_printf(" (%d) ", t); NL
	t = ft_printf("This long long as int:%i...", ll); 
	ft_printf(" (%d) ", t); NL

NL NL

	ll = LLONG_MIN;
	t = printf("This long long:%lli...", ll); 
	printf(" (%d) ", t); NL
	t = printf("This long long as int:%i...", ll); 
	printf(" (%d) ", t); NL
	t = ft_printf("This long long:%lli...", ll); 
	ft_printf(" (%d) ", t); NL
	t = ft_printf("This long long as int:%i...", ll); 
	ft_printf(" (%d) ", t); NL

NL NL

	double	f;

	f = DBL_MAX;
	t = printf("This float:%f...", f); 
	printf(" (%d) ", t); NL
	t = printf("This float as int:%i...", f); 
	printf(" (%d) ", t); NL
	t = ft_printf("This float:%f...", f); 
	ft_printf(" (%d) ", t); NL
	t = ft_printf("This float as int:%i...", f); 
	ft_printf(" (%d) ", t); NL

NL NL


	return (0);

}
