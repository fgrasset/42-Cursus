/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:13:28 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/21 15:44:37 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* function that returns the power of nb */
int	ft_pow(int nb, int power)
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
			res *= ft_pow(nb, power - 1);
		return (res);
	}	
}

/* strjoin but for one char and one string */
char	*ft_strchar(char *s1, char c)
{
	int		i;
	char	*ptr;
	int		len;

	i = -1;
	len = ft_strlen(s1);
	ptr = malloc((len + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (++i < len)
		ptr[i] = s1[i];
	ptr[i] = c;
	ptr[++i] = '\0';
	free(s1);
	return (ptr);
}

/* handler for SIGUSR, return bit 1 if SIGUSR1 and bit 0 if SIGUSR2
   and tranforms the result in ASCII character */
void	sigusr_handler(int sig)
{
	static int	result;
	static int	bit_count;
	static char	*str;

	if (sig == SIGUSR1)
	{
		result += ft_pow(2, bit_count);
		bit_count++;
	}
	else if (sig == SIGUSR2)
		bit_count++;

	if (bit_count == 8)
	{
		// ft_printf("%c", result);
		if (!str)
		{
			str = malloc(sizeof(char) * 1);
			str[0] = result;
		}
		else
			str = ft_strchar(str, result);
		if (result == 10)
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

	action.sa_handler = &sigusr_handler;
	action.sa_flags = SA_NODEFER;

	if (sigaction(SIGUSR1, &action, NULL) != 0)
	{
		ft_printf("Error installing SIGUSR1 handler\n");
		return 1;
	}
	if (sigaction(SIGUSR2, &action, NULL) != 0)
	{
		ft_printf("Error installing SIGUSR2 handler\n");
		return 1;
	}
	while (1)
	{
		pause();
	}
	return 0;
}
