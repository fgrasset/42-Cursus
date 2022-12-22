/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:35:50 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/22 17:05:18 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* function that returns nb at the power power */
int	ft_bpow(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		if (power > 1)
			res *= ft_bpow(nb, power - 1);
		return (res);
	}	
}

/* strjoin but for one char and one string */
char	*ft_bstrchar(char *s1, char c)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	ptr[i] = c;
	ptr[++i] = '\0';
	free(s1);
	return (ptr);
}

/* handler for SIGUSR, return bit 1 if SIGUSR1 and bit 0 if SIGUSR2
   and tranforms the result in ASCII character to stock it in a 
   string */
void	sigusr_bhandler(int sig)
{
	static int	result;
	static int	bit_count;
	static char	*str;

	if (sig == SIGUSR1)
		result += ft_bpow(2, bit_count);
	bit_count++;
	if (bit_count == 16)
	{
		if (!str)
		{
			str = malloc(sizeof(char) * 1);
			str[0] = 0;
		}
		str = ft_bstrchar(str, result);
		if (result == 0)
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		bit_count = 0;
		result = 0;
	}
}

/* main function, launches the server, prints the pid
   and waits until signal is received */
int	main()
{
	struct sigaction action;

	ft_printf("Process ID: %d\n", getpid());

	action.sa_handler = &sigusr_bhandler;
	action.sa_flags = SA_NODEFER;

	if (sigaction(SIGUSR1, &action, NULL) || sigaction(SIGUSR2, &action, NULL))
	{
		ft_printf("Error using handler\n");
		return 1;
	}
	while (1)
	{
		pause();
	}
	return 0;
}