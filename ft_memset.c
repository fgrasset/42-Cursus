/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:27:48 by fgrasset          #+#    #+#             */
/*   Updated: 2022/10/26 14:59:37 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    size_t  i;

    i = 0;
    while (i < len)
    {
        (unsigned char *) b[i] = '0' + c;
        i++;
    }
    ptr[i] = '\0';
    return (b);
}