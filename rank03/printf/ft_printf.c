# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>


void	ft_putstr(char *input, int	*len)
{
	int	i;

	i = -1;
	if (!input)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (input[++i])
		*len += write(1, &input[i], 1);
}

void	ft_putnbrs(long long int nbr, int base, int *len)
{
	char	*hexa = "0123456789abcdef";

	if (nbr < 0)
	{
		*len += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= base)
		ft_putnbrs((nbr / base), base, len);
	*len += write(1, &hexa[nbr % base], 1);
}

int	ft_printf(char *input, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, input);
	len = 0;
	if (input == NULL)
		return (0);
	i = -1;
	while (input[++i])
	{
		if (input[i] == '%' && (input[i + 1] == 's' | input[i + 1] == 'd' | input[i + 1] == 'x'))
		{
			i++;
			if (input[i] == 's')
				ft_putstr(va_arg(arg, char *), &len);
			else if (input[i] == 'd')
				ft_putnbrs((long long int)va_arg(arg, int), 10, &len);
			else if (input[i] == 'x')
				ft_putnbrs((long long int)va_arg(arg, unsigned int), 16, &len);
		}
		else
			len += write(1, &input[i], 1);
	}
	va_end(arg);
	return (len);
}

// int	main()
// {
// 	int	nb = 8;

// 	ft_printf("salut les top %d\n", nb);
// 	return (0);
// }
