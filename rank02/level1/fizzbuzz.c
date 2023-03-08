/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:12:20 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/08 16:28:12 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	putstr(char *str)
{
	int i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
}

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int n)
{
	if (n < 10)
		putchar(n+'0');
	else
	{
		putnbr(n / 10);
		n %= 10;
		putchar (n + '0');
	}
}

int	main()
{
	int	n = 0;

	while(++n <= 100)
	{
		if (n % 15 == 0)
			putstr("fizzbuzz");
		else if (n % 5 == 0)
			putstr("buzz");
		else if (n % 3 == 0)
			putstr("fizz");
		else
			putnbr(n);
		write(1, "\n", 1);
	}

}
