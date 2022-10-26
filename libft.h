/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:08:26 by fgrasset          #+#    #+#             */
/*   Updated: 2022/10/26 22:14:08 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>
#include <ctype.h>

size_t  ft_strlen(const char *s);

// void    ft_putstr(char str);

void    *ft_memset(void *b, int c, size_t len);

// void    ft_bzero(void *s, size_t n);

// void    *ft_memcpy(void *dst, const void *src, size_t n);

// void    *ft_memccpy(void *dst, const void *src, int c, size_t n);

// void    *ft_memmove(void *dst, const void *src, size_t n);

// void    *ft_memchr(const void *s, int c, size_t n);

// int     ft_memcmp(const void *s1, const void *s2, size_t n);

int     ft_isalnum(int c);

int     ft_isalpha(int c);

int     ft_isdigit(int c);

int     ft_isascii(int c);

int     ft_toupper(int c);

int     ft_tolower(int c);



#endif