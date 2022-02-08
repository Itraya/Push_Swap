# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:34:21 by mlagrang          #+#    #+#              #
#    Updated: 2022/02/08 10:08:37 by mlagrang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_fun.c	\
			srcs/ft_fun2.c	\
			srcs/ft_find.c	\
			srcs/ft_math.c	\
			srcs/ft_move.c	\
			srcs/ft_prep.c	\
			srcs/ft_sort_l.c	\
			srcs/ft_sort_s.c	\
			srcs/ft_sortneed.c	\
			srcs/ft_split.c	\
			main.c

HEADERS	= ft_PS.h

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o:	%.c	${HEADERS} Makefile
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

5:		all
		./${NAME} `ruby -e "puts (1..5).to_a.shuffle.join(' ')"` | wc -l

100:	all
		./${NAME} `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l

500:	all
		./${NAME} `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l

t:		all
		./${NAME} `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re 5 100 500 t
