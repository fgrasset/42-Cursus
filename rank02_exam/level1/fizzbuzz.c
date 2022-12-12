/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:24:50 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 16:16:31 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if(n < 10)
		ft_putchar(n + '0');
	else
		ft_putchar((n % 10) + '0');
		ft_putchar((n / 10) + '0');
}

int	main()
{
	int	i = 0;

	while (i < 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 3 == 0 && i % 5 != 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0 && i % 3 != 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
	write(1, "100\n", 4);
}