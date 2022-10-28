SRCS	= main.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
 ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c ft_bzero.c ft_memcpy.c\
 ft_isprint.c ft_memmove.c\

OBJS	= ${SRCS:.c=.o}

NAME 	= libft.a

CC 		= gcc 

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re