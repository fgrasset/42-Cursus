#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netinet/ip.h>

int	count, max_fd = 0;
int	ids[424242];
char	*msgs[424242];

fd_set	afds, rfds, wfds;
char	bufRead[4242], bufWrite[4242];

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void	fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void	sendAll(int excludedFd, char *str)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &wfds) && fd != excludedFd)
			send(fd, str, strlen(str), 0);
	}
}

void	sendMsg(int fd)
{
	char	*msg;

	while (extract_message(&(msgs[fd]), &msg))
	{
		sprintf(bufWrite, "client %d: ", ids[fd]);
		sendAll(fd, bufWrite);
		sendAll(fd, msg);
		free(msg);
	}
}

void	register_client(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(bufWrite, "server: client %d just arrived\n", ids[fd]);
	sendAll(fd, bufWrite);
}

void	remove_client(int fd)
{
	sprintf(bufWrite, "server: client %d just left\n", ids[fd]);
	sendAll(fd, bufWrite);
	free(msgs[fd]);
	FD_CLR(fd, &afds);
	close(fd);
}

int	create_socket()
{
	max_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (max_fd < 0)
		fatal_error();
	FD_SET(max_fd, &afds);
	return max_fd;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	FD_ZERO(&afds);
	int	sockfd = create_socket();

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)))) {
		fatal_error();
	}
	if (listen(sockfd, 128)) {
		fatal_error();
	}

	while(1)
	{
		rfds = wfds = afds;

		if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
			fatal_error();

		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
				continue;

			if (fd == sockfd)
			{
				int	client_fd = accept(sockfd, 0, 0);
				if (client_fd >= 0)
				{
					register_client(client_fd);
					break ;
				}
			}
			else
			{
				int	read_bytes = recv(fd, bufRead, 1000, 0);
				if (read_bytes <= 0)
				{
					remove_client(fd);
					break ;
				}
				bufRead[read_bytes] = '\0';
				msgs[fd] = str_join(msgs[fd], bufRead);
				sendMsg(fd);
			}
		}
	}
	return 0;
}
