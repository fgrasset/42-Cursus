/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:29:16 by fgrasset          #+#    #+#             */
/*   Updated: 2022/10/29 13:30:22 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;

    i = 0;
    if (ft_strlen(needle) > ft_strlen(haystack))
        return (NULL);
    if (needle[0] == '\0')
       return (&((char *)haystack)[i]);
    while (haystack[i] && i < len)
    {
        j = -1;
        if (haystack[i] == needle[0])
        {
            while (needle[++j] && (j < ft_strlen(needle)))
                if ((needle[j] != haystack[j + i]))
                    break;
            return (&((char *)haystack)[i]);
        }
        i++;
    }
    return (NULL);
}
