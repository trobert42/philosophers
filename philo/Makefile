# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zerudo <zerudo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:43:19 by trobert           #+#    #+#              #
#    Updated: 2022/10/10 15:46:50 by trobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philo.c\
		check_args.c\
		init.c\
		routine.c\
		check_routine.c\
		routine_utils.c\
		forks.c\
		libft_utils.c\
		error_free_quit.c\

SRCS = ${addprefix srcs/, ${SRC}}

OBJS = ${SRCS:.c=.o}

INC = -I./includes

NAME = philo

CC = cc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

TFLAGS = -pthread

all: ${NAME}

${NAME}: ${OBJS} includes/philo.h
	${CC} ${CFLAGS} ${TFLAGS} ${OBJS} ${INC} -o ${NAME} 

.c.o:
	${CC} ${CFLAGS} ${TFLAGS} ${INC} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ${BNAME}

re: fclean all

.PHONY: clean fclean bonus all re
