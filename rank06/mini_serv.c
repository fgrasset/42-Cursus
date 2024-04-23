#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct client {
	int id;
	char msg[100000];
}	t_client;

t_client	clients[1024];

int	max, next_id = 0;
fd_set	active, readyRead, readyWrite;
char bufRead[424242], bufWrite[424242];

void	exitError(char *str)
{
	if (str)
		write(2, str, strlen(str));
	exit(1);
}

void	sendAll(int excludedSocket)
{
	for (int fd = 0; fd <= max; fd++)
	{
		if (FD_ISSET(fd, &readyWrite) && fd != excludedSocket)
			send(fd, bufWrite, strlen(bufWrite), 0);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exitError("Wrong number of arguments");
	int	port = atoi(av[1]);

	int	listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listeningSocket < 0)
		exitError("Fatal error\n");

	bzero(clients, sizeof(clients));
	FD_ZERO(&active);

	max = listeningSocket;
	FD_SET(listeningSocket, &active);

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port);

	if (bind(listeningSocket, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		exitError("Fatal error\n");
	if (listen(listeningSocket, 128) < 0)
		exitError("Fatal error\n");

	while (1)
	{
		readyRead = readyWrite = active;
		if (select(max + 1, &readyRead, &readyWrite, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max; fd++)
		{
			if (FD_ISSET(fd, &active) && fd == listeningSocket)
			{
				int clientSocket = accept(fd, 0, 0);
				if (clientSocket < 0)
					continue;
				max = (clientSocket > max) ? clientSocket : max;
				clients[clientSocket].id = next_id++;
				FD_SET(clientSocket, &active);
				sprintf(bufWrite, "server: client %d just arrived\n", clients[clientSocket].id);
				sendAll(fd);
				break;
			}
			if (FD_ISSET(fd, &active) && fd != listeningSocket)
			{
				int	read = recv(fd, bufRead, strlen(bufRead), 0);
				if (read <= 0)
				{
					sprintf(bufWrite, "server: client %d just left\n", clients[fd].id);
					sendAll(fd);
					FD_CLR(fd, &active);
					close(fd);
					break ;
				}
				else
				{
					for (int i = 0, j = strlen(clients[fd].msg); i < read; i++, j++)
					{
						clients[fd].msg[j] = bufRead[i];
						if (clients[fd].msg[j] == '\n')
						{
							clients[fd].msg[j] = '\0';
							sprintf(bufWrite, "client %d: %s\n", clients[fd].id, clients[fd].msg);
							sendAll(fd);
							bzero(&clients[fd].msg, strlen(clients[fd].msg));
							j = -1;
						}
					}
					break;
				}
			}
		}
	}

}
