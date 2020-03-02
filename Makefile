# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 12:43:45 by fde-capu          #+#    #+#              #
#    Updated: 2020/03/02 19:33:54 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC		=	gcc

CC		=	$(GCC) $(FLAGS)	

FLAGS	=	-Wall -Wextra -Werror

AR		=	ar -rc

NAME	=	libftprintf.a

DEPLIB	=	libft/libft.a

SRCS	=	ft_printf.c	\
			typetable.c \
			ftpf_renders.c

OBJS	=	$(SRCS:.c=.o)

HEAD	=	ft_printf.h	

TOBJ	=	main.c

all:	dep $(NAME)

dep:
	cd libft && $(MAKE)

$(NAME):	$(OBJS)

$(OBJS):	$(SRCS)
	$(CC) -c $(SRCS)
	$(AR) $(NAME) $(OBJS) $(DEPLIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:			fclean all

cleandep:
	cd libft && $(MAKE) fclean

norm:
	cd libft && norminette -R CheckForbiddenSourceHeader *.c *.h
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(HEAD)

$(DEPLIB):	dep

test:		all
	$(CC) $(TOBJ) $(NAME) $(DEPLIB) -o ftpft
	./ftpft

rtest:		cleanall test

retest:		rtest

rt:			rtest

t:			test

cleanall:	fclean cleandep

st:			re test 

deliver:
	mkdir -p _deliver
	cp -p ft_printf.c _deliver
	cp -p typetable.c _deliver
	cp -p ftpf_renders.c _deliver
	cp -p Makefile _deliver
	cp -rfp libft _deliver
	cp -p ft_printf.h _deliver

tt:			deliver
	cp -prf _deliver/* ../zzz
	cd ../zzz/42TESTERS-PRINTF && ./runtest.sh
