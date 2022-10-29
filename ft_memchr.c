/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:55:06 by fgrasset          #+#    #+#             */
/*   Updated: 2022/10/28 13:55:06 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s == (NULL) && c == '\0')
		return (0);
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char )c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (0);
}
