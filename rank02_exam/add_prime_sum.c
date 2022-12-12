/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:34:21 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 14:15:44 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	isprime(int n)
{
	int	i;

	i = 3;
	if (n == 2)
		return 1;
	if (n == 1 || n % 2 == 0)
		return 0;
	while (i <= n/2)
	{
		if (n % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

int	ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
        	str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int n)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else	
		putnbr(n / 10);
}

int	main(int argc, char **argv)
{
	int	nb;
	int	i;
	int	res;

	nb = ft_atoi(argv[1]);
	if (argc > 1 || nb >= 0)
	{
		i = 1;
		res = 0;

		while (i <= nb)
		{
			if ((isprime(i)))
				res += i;
			i++;
		}
		putnbr(res);
		exit(1);
	}
	write(1, "0\n", 2);
}