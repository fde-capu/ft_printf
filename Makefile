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

CC =	gcc

FLAGS =	-Wall -Wextra -Werror

AR =	ar -rc

NAME =	libftprintf.a

DEPLIB = libft/libft.a

SRCS =	ft_printf.c

OBJS =	$(SRCS:.c=.o)

TOBJ =	main.c

all :	dep $(NAME)

dep :
	cd libft && $(MAKE) bonus

cleandep:
	cd libft && $(MAKE) fclean

$(DEPLIB) :	dep

$(SRCS) :
	$(CC) -o $(OBJS) -c $(DEPLIB) $(SRCS) $(FLAGS) 

$(NAME) :	$(OBJS)
	$(AR) $(NAME) $(DEPLIB) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

cleanall: fclean cleandep

re:		cleanall all

norm:
	cd libft && norminette -R CheckForbiddenSourceHeader *.c *.h
	norminette -R CheckForbiddenSourceHeader *.c *.h

test:	all
	$(CC) $(FLAGS) $(NAME) $(TOBJ) -o ftpft
	./ftpft

rtest:	re test

retest:	rtest

rt:		rtest

t:	test
