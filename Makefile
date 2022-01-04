# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 15:34:21 by mlagrang          #+#    #+#              #
#    Updated: 2021/12/29 10:13:30 by mlagrang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_fun.c srcs/ft_fun2.c srcs/ft_needs.c srcs/ft_needs2.c srcs/ft_needs3.c srcs/ft_sort_l.c main.c srcs/ft_sort_s.c srcs/ft_sortneed.c srcs/ft_split.c

SRCSCH	= srcs/ft_fun.c srcs/ft_fun2.c srcs/ft_needs.c srcs/ft_needs2.c srcs/ft_needs3.c srcs/ft_sort_l.c srcs/ft_sort_s.c srcs/ft_sortneed.c srcs/ft_split.c get_next_line.c get_next_line_utils.c checker.c

HEADERS	= ft_PS.h

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

NAMECH	= checker

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o:%.c	ft_PS.h
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ft_PS.h

${NAME}:	${SRCS}
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all:	${NAME}

checker:	${SRCSCH}
			${CC} ${CFLAGS} ${SRCSCH} -o ${NAMECH}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME} ${NAMECH}

re:		fclean all

rechecker:	fclean checker

rett:	fclean all checker

.PHONY:	all clean fclean re bonus checker rechecker rett
