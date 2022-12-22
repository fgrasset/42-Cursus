SOURCES = server.c client.c server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: server client server_bonus client_bonus

server_bonus: server_bonus.o ft_printf/libftprintf.a
	$(CC) -o $@ $^

client_bonus: client_bonus.o ft_printf/libftprintf.a
	$(CC) -o $@ $^

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
	rm -f server client server_bonus client_bonus ft_printf/libftprintf.a

re: fclean all

.PHONY: all bonus clean fclean re