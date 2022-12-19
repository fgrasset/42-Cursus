/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:13:28 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/19 17:03:11 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*str;

// /* handler for SIGUSR, return bit 1 if SIGUSR1 and bit 0 if SIGUSR2 */
// void	sigusr_handler(int sig)
// {
// 	static int index;

// 	if (!index || index == 7)
// 		index = 0;
	
// 	if (sig == SIGUSR1)
// 	{
// 		bits[index] = 1;
// 		index++;
// 	}
// 	else if (sig == SIGUSR2)
// 	{
// 		bits[index] = 0;
// 		index++;
// 	}
// }

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

// /* takes the 8-bit integer and prints it */
// void	get_bit(int bits[])
// {
// 	int	i;
// 	int	ascii;

// 	i = 0;
// 	ascii = 0;
// 	// to_print += bits[i] * (1 << i);
// 	// i++;
// 	// while (i < 8)
// 	// {
// 	// 	to_print *= 10;
// 	// 	to_print += bits[i] * (1 << i);
// 	// 	i++;
// 	// }

// 	while (i < 8)
// 	{
// 		printf("%d\n", bits[i]);
// 		if (bits[i] == '1')
// 		{
// 			ascii += ft_pow(2, i);
// 		}
// 		i++;
// 	}
// 	printf("%d\n", ascii);
// 	// str = ft_strjoin(str, ft_itoa(ascii));
// }

/* strjoin but for one char and one string */
char	*ft_strchar(char const *s1, char s2)
{
	size_t	i;
	char	*ptr;

	i = -1;
	ptr = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	i++;
	ptr[i] = s2;
	i++;
	ptr[i] = '\0';
	return (ptr);
}

/* handler for SIGUSR, return bit 1 if SIGUSR1 and bit 0 if SIGUSR2
   and tranforms the result in ASCII character */
void	sigusr_handler(int sig)
{
	static int	result;
	static int	bit_count;
	static char	*str;

	if (!bit_count || bit_count == 8)
	{
		bit_count = 0;
		result = 0;
	}
	if (sig == SIGUSR1)
	{
		result += ft_pow(2, bit_count);
		bit_count++;
	}
	else if (sig == SIGUSR2)
		bit_count++;

	if (bit_count == 8)
	{
		if (!str)
			str = malloc(sizeof(char) * 1);
		str = ft_strchar(str, (char) result);
		if (result == 10)
			printf("%s", str);
	}
}


/* main function, launches the server until signal is received */
int	main()
{
	struct sigaction action;

	printf("Process ID: %d\n", getpid());

	action.sa_handler = &sigusr_handler;
	action.sa_flags = SA_NODEFER;

	if (sigaction(SIGUSR1, &action, NULL) != 0)
	{
		printf("Error installing SIGUSR1 handler\n");
		return 1;
	}
	if (sigaction(SIGUSR2, &action, NULL) != 0)
	{
		printf("Error installing SIGUSR2 handler\n");
		return 1;
	}

	while (1)
	{
		pause();
	}

	return 0;
}


// /* main function, launches the server until signal is received */
// int	main()
// {
// 	struct sigaction action;
// 	int	i;

// 	printf("Process ID: %d\n", getpid());
// 	action.sa_handler = &sigusr_handler;
// 	action.sa_flags = SA_NODEFER;
// 	i = 0;
// 	sigaction(SIGUSR1, &action, NULL);
// 	sigaction(SIGUSR2, &action, NULL);
// 	// if (!sigaction(SIGUSR1, &action, NULL) || !sigaction(SIGUSR2, &action, NULL))
// 	// {
// 	// 	write(1,"test",4);
// 	// 	if (i == 7)
// 	// 	{
// 	// 		print_bit();

// 	// 		i = 0;
// 	// 	}
// 	// 	i++;
// 	// }

// 	while(1)
// 	{
// 		pause();
// 	}

// 	return 0;
// }

// #include "minitalk.h"

// int	bits[8];
// int	bit_count = 0;

// /* takes the 8-bit integer and prints it */
// void	print_bit()
// {
// 	int	i;
// 	int	to_print;

// 	to_print = 0;
// 	for (i = 0; i < 8; i++)
// 	{
// 		to_print *= 10;
// 		to_print += bits[i] * (1 << i);
// 	}
// 	write(1, &to_print, 1);
// }

