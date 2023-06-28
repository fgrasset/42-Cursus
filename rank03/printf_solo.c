	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_solo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:53:13 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/19 10:29:35 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_print_nb(long long int n, int base, int *res);
void	ft_print_s(char *str, int *res);
int	ft_printf(char *str, ...);

int	main(int ac, char **av)
{
	(void) ac;

	ft_printf("this is a %d and %s\n", -12456, av[1]);
	ft_printf("this ishexa %x\n", 42);


	return (0);
}

int	ft_printf(char *str, ...)
{
	int	res = 0;
	int	i = -1;
	va_list	args;

	va_start(args, str);

	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_print_s(va_arg(args, char *), &res);
			else if (str[i] == 'd')
				ft_print_nb((long long int)va_arg(args, int), 10, &res);
			else if (str[i] == 'x')
				ft_print_nb((long long int)va_arg(args, unsigned int), 16, &res);
		}
		else
		{
			res += write(1, &str[i], 1);
		}
	}

	va_end(args);
	return (res);
}

void	ft_print_nb(long long int n, int base, int *res)
{
	char	*hexa = "0123456789abcdef";

	if (n < 0)
	{
		*res += write(1, "-", 1);
		n *= -1;
	}
	if (n > base)
		ft_print_nb((n / base), base, res);
	*res += write(1, &hexa[n % base], 1);
}

void	ft_print_s(char *str, int *res)
{
	int	i = -1;

	if (!str)
	{
		res += write(1, "(null)", 6);
		return ;
	}
	while (str[++i])
	{
		res += write(1, &str[i], 1);
	}
}

