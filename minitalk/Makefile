# SRCS	= client.c server.c

# OBJS	= ${SRCS:.c=.o}

# NAME	= minitalk.a

# PRINTF	= ../ft_printf

# CC 		= gcc

# RM 		= rm -f

# CFLAGS 	= -Wall -Werror -Wextra

# .c.o:
# 			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# ${NAME}:	${OBJS}
# 			@make -C $(PRINTF)
# 			@cp printf/libftprintf.a
# 			@mv libftprintf.a $(NAME)
# 			ar rcs ${NAME} ${OBJS}

# all:		${NAME}

# clean:
# 			${RM} ${OBJS}
# 			@make clean -C $(PRINTF)

# fclean:		clean
# 			${RM} ${NAME}
# 			@$(RM) -f $(PRINTF)/libftprintf.a

# re:			fclean all

# .PHONY:		all clean fclean re


SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: server client

bonus: server client

server: server.o ft_printf/libftprintf.a
	$(CC) -o $@ $^

client: client.o ft_printf/libftprintf.a
	$(CC) -o $@ $^ 

%.o: %.c
	$(CC) -c $(CFLAGS) $?

ft_printf/libftprintf.a:
	@make -C ft_printf

clean:
	rm -f $(OBJECTS)
	@make -C ft_printf clean

fclean: clean
	rm -f server client ft_printf/libftprintf.a

re: fclean all

.PHONY: all bonus clean fclean re