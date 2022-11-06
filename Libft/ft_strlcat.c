/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:40:05 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/06 14:25:07 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;

	i = 0;
	lendst = ft_strlen(dst);
	if (dstsize == 0)
		return ((size_t)ft_strlen(src));
	while (i <= (dstsize - lendst - 1) && (i <= ft_strlen(src)))
	{
		dst[i + lendst + 1] = src[i];
		i++;
	}
	dst[i + lendst + 1] = '\0';
	return ((size_t)(ft_strlen(src) + lendst));
}
