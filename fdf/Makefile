# SOURCES = $(wildcard */*.c *.c)
# OBJECTS = $(SOURCES:.c=.o)

# CC = gcc
# CFLAGS = -Wall -Wextra -g

# NAME = fdf.a

# all: ${NAME}

# fdf: $(OBJECTS) libft/libft.a mlx/libmlx.a
# 	$(CC) -o $@ $^

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $< -o $@

# ${NAME}: ${OBJECTS}
# 	$(CC) $^ -lmlx -lXext -lX11 -o ${NAME}

# libft/libft.a:
# 	@make -C libft libft.a

# mlx/libmlx.a:
# 	@make -C mlx libmlx.a

# clean:
# 	rm -f $(OBJECTS)
# 	@make -C libft clean
# 	@make -C mlx clean

# fclean: clean
# 	rm -f fdf libft/libft.a mlx/libmlx.a

# re: fclean all

# .PHONY: all bonus clean fclean re

SRCS	= $(wildcard *.c)

OBJS	= $(SRCS:%.c=%.o)

NAME	= fdf

CC		= gcc -g
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror #-fsanitize=address

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -I./mlx -c $? -o $@

${NAME}:		${OBJS}
		@$(MAKE) -C libft
		@$(MAKE) -C mlx
		${CC} ${CFLAGS} $^ -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

libft:
		make -C libft

mlx:
		make -C mlx

clean:
			make clean -C libft
			make clean -C mlx
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		libft all bonus clean fclean re
