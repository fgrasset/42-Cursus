/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:38:37 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/23 16:45:27 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* handler for recevied message */
void	sigusr_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message well received 🎅");
	exit(1);
}

/* takes a character and returns a 8 bit integer of the character */
void	send(char c, int pid)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		bit = (c & (1 << i)) != 0;
		if (bit % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		i++;
	}
}

/* prepares the message and the pid in arguments,
   and activates the function to send it to the server,
   then it send the pid of the client and finally 
   gets confirmation of received message */
int	main(int ac, char **av)
{
	int					i;
	int					pid_server;
	char				*pid_client;
	struct sigaction	action;

	if (ac != 3)
		return (printf("Please write only the PID of the \
		server and the string you want to send\n"));
	action.sa_handler = &sigusr_handler;
	action.sa_flags = SA_NODEFER;
	sigaction(SIGUSR1, &action, NULL);
	pid_server = ft_atoi(av[1]);
	pid_client = ft_itoa(getpid());
	i = -1;
	while (av[2][++i])
		send(av[2][i], pid_server);
	send(0, pid_server);
	i = -1;
	while (pid_client[++i])
		send(pid_client[i], pid_server);
	send(0, pid_server);
	free(pid_client);
	while (1)
		pause();
}
