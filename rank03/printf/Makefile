SRCS	= printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

LIBFT	= libft

CC 		= gcc

RM 		= rm -f

CFLAGS 	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}
			@make clean -C $(LIBFT)

fclean:		clean
			${RM} ${NAME}
			@$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re
