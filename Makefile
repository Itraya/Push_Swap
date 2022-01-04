# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:34:21 by mlagrang          #+#    #+#              #
#    Updated: 2022/01/04 12:20:11 by mlagrang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_fun.c srcs/ft_fun2.c srcs/ft_needs.c srcs/ft_needs2.c srcs/ft_needs3.c srcs/ft_sort_l.c main.c srcs/ft_sort_s.c srcs/ft_sortneed.c srcs/ft_split.c

HEADERS	= ft_PS.h

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra

%.o:	%.c	${HEADERS} Makefile
		${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all:	${NAME}

5:		all
		./${NAME} `ruby -e "puts (1..5).to_a.shuffle.join(' ')"`

100:	all
		./${NAME} `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` 

500:	all
		./${NAME} `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` 

t:		all
		./${NAME} `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re 5 100 500 t
