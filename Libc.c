/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:02:35 by fabien            #+#    #+#             */
/*   Updated: 2022/10/17 16:52:03 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct size {
    unsigned char;
} size_t;

int    ft_strlen(char str)
{
    int i;

    i = 0;
    while(str)
        i++;

    return (i);
}

void    ft_putstr(char str)
{
    int len;

    len = ft_strlen(str);
    while(len >= 0)
    {

    }
}

void    *ft_memset(void *b, int c, size_t len)
{
    int i;
    char str[100];

    i = 0;
    while (i <= len)
    {
        str[i] = '0' + c;
        i++; 
    }

    b = str;
    return (b);
}

void    ft_bzero(void *s, size_t n)
{
    int i;
    char str[100];

    i = 0;
    while (i <= len)
    {
        str[i] = '0';
        i++; 
    }

    s = str;
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    int i;
    char    str[n];

    i = 0;
    while (n >= 0)
    {
        str[i] = *(src + i);
        i++;
    }
}

void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
{

}

void    *ft_memmove(void *dst, const void *src, size_t n)
{

}

void    *ft_memchr(const void *s, int c, size_t n)
{

}

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{

}

size_t  ft_strlen(const char *s)
{

}

int     ft_isalpha(int c)
{
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c >= 'z'))
        return (1);
    else
        return (0);
}

int     ft_isdigit(int c)
{
    if(c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int     ft_isalnum(int c)
{
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c >= 'z') || (c >= '0' && c <= '9'))
        return (1);
    else
        return (0);
}

int     ft_isascii(int c)
{

}

int     ft_isprint(int c)
{

}

int     ft_toupper(int c)
{

}

int     ft_tolower(int c)
{

}

char    *ft_strchr(const char *s, int c)
{

}

char    *ft_strrchr(const char *s, int c)
{

}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{

}

size_t  ft_strlcpy(char *dst, const char *src, size_t destsize)
{

}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{

}

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{

}

int     ft_atoi(const char *str)
{

}