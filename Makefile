# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 12:43:45 by fde-capu          #+#    #+#              #
#    Updated: 2020/03/06 12:06:46 by fde-capu         ###   ########.fr        #
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

cleanall:	fclean cleandep xdeliver
	rm -rf ./$(EXECNM).dSYM
	rm -f $(EXECNM)

st:			re test 

val:
	rm -rf ./$(EXECNM).dSYM
	valgrind --dsymutil=yes --track-origins=yes ./$(EXECNM)
	#valgrind --dsymutil=yes --track-origins=yes --leak-check=full ./$(EXECNM)
	#valgrind --dsymutil=yes --track-origins=yes --leak-check=full ./$(EXECNM)

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
	cd ../zzz && $(MAKE) cleanall
	cp -prf _deliver/* ../zzz
	cd ../zzz/42TESTERS-PRINTF && ./runtest.sh

t2:			deliver
	cp -prf _deliver/* ../zzz
#to do
