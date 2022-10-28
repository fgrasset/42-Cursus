/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:54:55 by fgrasset          #+#    #+#             */
/*   Updated: 2022/10/28 10:55:05 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;

    i = ft_strlen(src);
    char buffer[i];

    i = 0;
    while (i < len)
    {
        buffer[i] = *(char*)(src + i);
        i++;
    }
    i = 0;
    while (i < len)
    {
        *(char*)(dst + i) = buffer[i]; 
        i++;
    }
    return (dst);
}