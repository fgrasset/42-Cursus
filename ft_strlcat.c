/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:40:05 by fgrasset          #+#    #+#             */
/*   Updated: 2022/10/29 12:12:03 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (dstsize == 0 || src == (NULL))
		return ((size_t)ft_strlen(src));
	while (i <= (dstsize - j - 1) && (i < ft_strlen(src)))
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ((size_t)(ft_strlen(src) + ft_strlen(dst)));
}
