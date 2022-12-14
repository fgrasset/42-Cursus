/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:58:04 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 09:43:57 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i = 0;

	while(s[i])
		i++;
	return i;
}

void	is_word(char *s, int i)
{
	char	tmp = s[i];

	s = realloc(s, ft_strlen(s + 2));
	s[i] = '_';
	s[i + 1] = tmp + 32;
}

void	ft_putstr(char *s)
{
	int	i = 0;

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		char	*camel = malloc(sizeof(char) * ((ft_strlen(av[1]) + 1)));
		int		i = 0;

		while(av[1][i])
		{
			camel[i] = av[1][i];
			i++;
		}
		camel[i] = '\0';
		i = -1;
		while (camel[i])
		{
			i++;
			if (camel[i] >= 'A' && camel[i] <= 'Z')
				{
					is_word(camel, i);
					i += 2;
				}
		}
		i = 0;
		ft_putstr(camel);
		free(camel);
	}
	write(1, "\n", 1);
}