/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:12:03 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/11 17:12:36 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// typedef struct print
// {
// 	va_list args;
// 	int	sgn;
// 	int	prc;
// 	int	len;
// 	char	**s;
// }print;

# include <stdarg.h>
# include "Libft/libft.h"

int	ft_printf(const char *string, ...);
int	printf_c(char c);
int	printf_s(char *s);
int	printf_prc();
int	printf_d(int n);
int	printf_u(unsigned int n);

#endif