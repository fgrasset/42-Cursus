SRCS	= $(wildcard *.c)

OBJS	= $(SRCS:%.c=%.o)

NAME	= philo

CC		= gcc -g
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror# -fsanitize=address
TFLAGS	= -lpthread -fsanitize=thread

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -c $? -o $@

${NAME}:		${OBJS}
		${CC} ${CFLAGS} $^ ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
