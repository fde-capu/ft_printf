# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 12:43:45 by fde-capu          #+#    #+#              #
#    Updated: 2020/03/03 12:08:46 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC		=	gcc

CC		=	$(GCC) $(FLAGS)	

FLAGS	=	-Wall -Wextra -Werror

AR		=	ar -rcs

NAME	=	libftprintf.a
NAMESHORT = ftprintf

DEPPATH =	./libft
DEPLIB	=	libft.a
DEPLSHORT =	ft

SRCS	=	ft_printf.c	\
			typetable.c \
			ftpf_renders.c

OBJS	=	$(SRCS:.c=.o)
DEPOBJS =	$(DEPPATH)/*.o

HEAD	=	ft_printf.h	

TOBJ	=	main.c

all:	dep $(NAME)

dep:
	cd libft && $(MAKE)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS) $(DEPOBJS)

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
	$(CC) $(TOBJ) -L. -l$(NAMESHORT) -o ftpft
	./ftpft

rtest:		cleanall test

retest:		rtest

rt:			rtest

t:			test

cleanall:	fclean cleandep xdeliver

st:			re test 

deliver:
	mkdir -p _deliver
	cp -p ft_printf.c _deliver
	cp -p typetable.c _deliver
	cp -p ftpf_renders.c _deliver
	cp -p Makefile _deliver
	cp -rfp libft _deliver
	cp -p ft_printf.h _deliver

xdeliver:
	rm -rf _deliver

tt:			deliver
	cp -prf _deliver/* ../zzz
	cd ../zzz/42TESTERS-PRINTF && ./runtest.sh
