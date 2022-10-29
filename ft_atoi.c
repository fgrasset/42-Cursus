/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:57:05 by fgrasset          #+#    #+#             */
/*   Updated: 2022/10/29 14:57:05 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int  ft_isspace(int c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return (1);
    return(0);
}

static int  ft_issgn(int c)
{
    if (c == '-')
        return (-1);
    else if (c == '+')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int     i;
    int     sgn;
    int     atoi;

    i = -1;
    atoi = 0;
    while (str[++i])
    {
        if (!ft_isspace(str[i]) || !ft_issgn(str[i]) || !ft_isdigit(str[i]))
            break;
        if (ft_issgn(str[i]))
            sgn = ft_issgn(str[i]);
        if (ft_isdigit(str[i]))
        {
            while (ft_isdigit(str[i + 1]))
            {
                atoi = (atoi * 10) + (str[i] + '0');
                i++;
            }
            atoi = (atoi * 10) + (str[i] + '0');
            return (atoi * sgn);
        }
    }
    return (0);
}