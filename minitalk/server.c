/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:13:28 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/16 15:29:00 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* handler for SIGUSR1, return bit 0 */
void	sigusr1_handler(int sig)
{

}

/* handler for SIGUSR2, return bit 1 */
void	sigusr2_handler(int sig)
{

}

/* main function, launches the server until signal is revceived */
int	main(int ac, char **av)
{
	while(1)
	{
		pause();
	}
}