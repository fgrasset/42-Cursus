/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:51:37 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/18 13:59:51 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_printf_d(int nb, int base, int *res);
void	ft_printf_s(char *str, int *res);
int		ft_printf(char *str, ...);


int	main(int ac, char **av)
{
	(void) ac;

	ft_printf("this is a %d and %s\n", -12456, av[1]);
	ft_printf("this ishexa %x\n", 42);


	return (0);
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i = -1;
	int		res = 0;

	va_start(args, str);

	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
				ft_printf_d((int)va_arg(args, int), 10, &res);
			else if (str[i] == 's')
				ft_printf_s(va_arg(args, char *), &res);
			else if (str[i] == 'x')
				ft_printf_d((int)va_arg(args, unsigned int), 16, &res);
		}
		else
			res += write(1, &str[i], 1);
	}
	va_end(args);
	return (res);
}

void	ft_printf_d(int nb, int base, int *res)
{
	char *hexa = "0123456789abcdef";

	if (nb < 0)
	{
		nb *= -1;
		*res += write(1, "-", 1);
	}
	if (nb >= base)
		ft_printf_d((nb / base), base, res);
	*res += write(1, &hexa[nb % base], 1);
}

void	ft_printf_s(char *str, int *res)
{
	int	i = -1;

	if (!str)
	{
		*res += write(1, "(null)", 6);
		return ;
	}
	while (str[++i])
	{
		*res += write(1, &str[i], 1);
	}
}
