# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 12:43:45 by fde-capu          #+#    #+#              #
#    Updated: 2020/02/03 15:34:11 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

AR		=	ar -rc

NAME	=	libftprintf.a

DEPLIB	=	src/libft/libft.a

SRCS	=	src/ft_printf.c

OBJS	=	$(SRCS:.c=.o)

TOBJ	=	main.c

all:	dep $(NAME)

dep:
	cd src/libft && $(MAKE)

$(SRCS):
	$(CC) $(FLAGS) -o $(OBJS) -c $(SRCS)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS) $(DEPLIB)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:			fclean all

cleandep:
	cd src/libft && $(MAKE) fclean

norm:
	cd src/libft/src && norminette -R CheckForbiddenSourceHeader *.c *.h
	cd src && norminette -R CheckForbiddenSourceHeader *.c *.h

$(DEPLIB):	dep

test:		all
	$(CC) $(FLAGS) $(TOBJ) $(NAME) $(DEPLIB) -o ftpft
	./ftpft

rtest:		cleanall test

retest:		rtest

rt:			rtest

t:			test

cleanall:	fclean cleandep

st:			re test 
