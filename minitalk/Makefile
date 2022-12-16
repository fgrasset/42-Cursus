SRCS	= client.c server.c

OBJS	= ${SRCS:.c=.o}

NAME	= minitalk.a

PRINTF	= printf

CC 		= gcc

RM 		= rm -f

CFLAGS 	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@make -C $(PRINTF)
			@cp printf/libftprintf.a
			@mv libftprintf.a $(NAME)
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}
			@make clean -C $(PRINTF)

fclean:		clean
			${RM} ${NAME}
			@$(RM) -f $(PRINTF)/libftprintf.a

re:			fclean all

.PHONY:		all clean fclean re