/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:34:23 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 11:45:59 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	atoi(char *s)
{
	int	res = 0;
	int	i = 0;

	while (s[i])
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return res;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
	{
		ft_putchar(n + '0');
	}
}


int	main(int ac, char **av)
{
	
	if (ac == 2)
	{
		int	n = 1;

		while(n < 10)
		{
			ft_putchar(n + '0');
			ft_putchar(' ');
			ft_putchar('x');
			ft_putchar(' ');
			ft_putnbr(atoi(av[1]));
			ft_putchar(' ');
			ft_putchar('=');
			ft_putchar(' ');
			ft_putnbr(n * atoi(av[1]));
			write(1,"\n",1);
			n++;
		}
	}
	write(1, "\n", 1);
}