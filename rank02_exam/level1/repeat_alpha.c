/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:25:02 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 16:37:16 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	to_print(char c, int repeat)
{
	while (repeat)
	{
		ft_putchar(c);
		repeat--;
	}
}

int	alpha(char c)
{
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	char *Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int	i = 0;

	if (c >= 'a' && c <= 'z')
	{
		while (alphabet[i] != c)
			i++;
		return i;
	}
	else if (c >= 'A' && c <= 'Z')
	{
		while (Alphabet[i] != c)
			i++;
		return i;
	}
	else
		return 1;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;

		while (av[1][i])
		{
			to_print(av[1][i], alpha(av[1][i])+1);
			i++;
		}
	}
	write(1, "\n", 1);
}