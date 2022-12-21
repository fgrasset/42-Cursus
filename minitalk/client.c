/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:13:44 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/21 11:05:04 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		kill(pid, (bit % 2) == 0 ? SIGUSR2 : SIGUSR1);
		ft_printf("%d\n", (bit % 2) == 0 ? 0 : 1);
		usleep(100);
		i++;
	}
}

/* prepares the message and the pid in arguments, and activates the function to send it to the server */
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i;
		int	pid;

		pid = atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			send(av[2][i], pid);
			i++;
		}
		send('\n', pid);
	}
	else
		printf("Please write only the PID of the server and the string you want to send\n");
}
