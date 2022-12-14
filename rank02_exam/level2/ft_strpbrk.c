/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:05:11 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/14 10:11:51 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_found(char c, const char *s2)
{
	int	i = 0;

	while (s2[i])
	{
		if (c == s2[i])
			return i;
		i++;
	}
	return 0;
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i = 0;

	while (*s1)
	{
		if (is_found(s1[i], s2))
			return ((char *)s1);
		s1++;
	}
	return NULL;
}

int	main(int ac, char **av)
{
	(void) ac;
	printf("%s\n", ft_strpbrk(av[1], av[2]));
}