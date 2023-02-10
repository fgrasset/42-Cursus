SOURCES = server.c client.c server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: server client server_bonus client_bonus

server_bonus: server_bonus.o libft/libft.a
	$(CC) -o $@ $^

client_bonus: client_bonus.o libft/libft.a
	$(CC) -o $@ $^

server: server.o libft/libft.a
	$(CC) -o $@ $^

client: client.o libft/libft.a
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft/libft.a:
	@make -C libft

clean:
	rm -f $(OBJECTS)
	@make -C libft clean

fclean: clean
	rm -f server client server_bonus client_bonus libft/libft.a

re: fclean all

.PHONY: all bonus clean fclean re
