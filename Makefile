# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 12:43:45 by fde-capu          #+#    #+#              #
#    Updated: 2020/03/11 16:04:26 by fde-capu         ###   ########.fr        #
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
EXECNM	=	ftpft

all:	dep $(NAME)

dep:
	cd libft && $(MAKE)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS) $(DEPOBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:			cleanall all

cleandep:
	cd libft && $(MAKE) fclean

norm:
	cd libft && norminette -R CheckForbiddenSourceHeader *.c *.h
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(HEAD)

$(DEPLIB):	dep

test:		all
	gcc -g $(TOBJ) -L. -l$(NAMESHORT) -o $(EXECNM)
	./$(EXECNM)

rtest:		cleanall test

retest:		rtest

rt:			rtest

t:			test

cleanall:	fclean cleandep xok xft
	rm -rf ./$(EXECNM).dSYM
	rm -f $(EXECNM)

st:			re test 

val:	t
	rm -rf ./$(EXECNM).dSYM
	valgrind --dsymutil=yes --track-origins=yes --leak-check=full ./$(EXECNM)

okcopy:	xok
	mkdir -p _ok
	cp -p ft_printf.c _ok
	cp -p typetable.c _ok
	cp -p ftpf_renders.c _ok
	cp -p Makefile _ok
	cp -Rfp libok _ok
	cp -p ft_printf.h _ok

ftcopy: xft
	mkdir -p _ft
	cp -p ft_printf.c _ft
	cp -p typetable.c _ft
	cp -p ftpf_renders.c _ft
	cp -p Makefile _ft
	cp -Rfp libok _ft
	cp -p ft_printf.h _ft

ft: okcopy xft
	git clone vogsphere@vogsphere.42sp.org.br:intra/2020/activities/42cursus_ft_printf/fde-capu _ft
	rm -rf _ft/*
	cp -Rfp _ok/* _ft
	cd _ft && git add * && git commit -m 'ft_printf :)' && git push

xok:
	rm -rf _ok

xft:
	rm -rf _ft

tt:			okcopy
	cp -Rpf _ok/* ../zzz
	cd ../zzz && $(MAKE) cleanall
	cd ../zzz/42TESTERS-PRINTF && ./runtest.sh

t2:			okcopy
	cp -Rpf _ok/* ../zzz
	cd ../zzz && $(MAKE) cleanall
	cd ../zzz/pft_2019 && $(MAKE) && ./test
