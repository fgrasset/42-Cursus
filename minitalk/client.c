/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:13:44 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/16 16:06:33 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* handler for SIGUSR, return bit 1 if SIGUSR1 and bit 0 if SIGUSR2 */
void	sigusr_handler(int sig)
{
	if (sig == SIGUSR1)
	{

	}
	else if (sig == SIGUSR2)
	{

	}
}

/* takes a character and returns a 8 bit integer of the character */
int	atob(char c)
{
	/* create an int and put the bit of the c char in ASCII into it. Do *10 each time to increment it */
}

/* prepares the message and the pid in arguments, and activates the function to send it to the server */
int	main(int ac, char **av)
{

}
