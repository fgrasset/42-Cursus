/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:09:07 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/12 18:51:27 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_x(unsigned int n)
{
	int		len;

	len = 0;

	if (n >= 16)
	{
		printf_x(n / 16);
		printf_x(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd((n - 10) + 'a', 1);
	}
	// alpha = ft_itoa(n);
	// len = ft_strlen(alpha);
	// free(alpha);
	return (sizeof(n)/4);	
}