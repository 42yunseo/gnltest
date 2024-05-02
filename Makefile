# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunseo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 18:06:47 by yunseo            #+#    #+#              #
#    Updated: 2024/04/29 18:06:48 by yunseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main
NAME_B = bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	./main.c \
		../get_next_line.c \
		../get_next_line_utils.c \

SRCS_B = 	./bonus.c \
			../get_next_line_bonus.c \
			../get_next_line_utils_bonus.c

all : ${NAME} bonus

${NAME} : ${OBJS} ${HEADER}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

bonus : 
	${CC} ${CFLAGS} ${SRCS_B} -o ${NAME_B}

clean : 
	rm -f ${NAME} ${NAME_B}
	rm -f line.txt newline.txt
	rm -f output1.txt output2.txt output3.txt

re : clean all

.PHONY : all clean re bonus
