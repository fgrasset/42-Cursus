SRCS	= main.c $(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

NAME 	= libft.a

CC 		= cc 

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} && ./libft.a && ${RM} libft.a && ${RM} *.o

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			flcean all

.PHONY:		all clean fclean re