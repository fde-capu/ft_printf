# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 12:43:45 by fde-capu          #+#    #+#              #
#    Updated: 2020/03/02 16:59:38 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC		=	gcc

CC		=	$(GCC) $(FLAGS)	

FLAGS	=	-Wall -Wextra -Werror

AR		=	ar -rcs

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

$(SRCS):
	$(CC) -o $(OBJS) -c $(SRCS)

$(NAME):	$(OBJS)
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
	mkdir _deliver
	cp ft_printf.c _deliver
	cp typetable.c _deliver
	cp ftpf_renders.c _deliver
	cp Makefile _deliver
	cp -rf libft _deliver
	cp ft_printf.h _deliver
