/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:13:28 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/17 15:01:08 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bits[8];

/* handler for SIGUSR, return bit 1 if SIGUSR1 and bit 0 if SIGUSR2 */
void	sigusr_handler(int sig)
{
	static int index;

	if (!index || index == 8)
		index = 0;
	
	if (sig == SIGUSR1)
	{
		bits[index] = 1;
		index++;
	}
	else if (sig == SIGUSR2)
	{
		bits[index] = 0;
		index++;
	}
}

/* takes the 8-bit integer and prints it */
void	print_bit()
{
	int	i;
	int	to_print;

	i = 0;
	to_print = 0;
	while (i < 8)
	{
		to_print += bits[i] * (1 << i);
		i++;
	}
	write(1, &to_print, 1);
}

/* main function, launches the server until signal is received */
int	main()
{
	struct sigaction action;
	int	i;

	printf("Process ID: %d\n", getpid());
	action.sa_handler = &sigusr_handler;
	i = 0;
	if (sigaction(SIGUSR1, &action, NULL) || sigaction(SIGUSR2, &action, NULL))
	{
		if (i == 8)
		{
			print_bit();
			
			i = 0;
		}
		i++;
	}

	while(1)
	{
		pause();
	}

	return 0;
}