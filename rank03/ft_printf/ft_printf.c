# include <unistd.h>
# include <stdarg.h>

void	putstr(char *input, int *len);
void	putnbr(long long int nbr, int base, int *len);

// int	ft_printf(char *input, ...)
// {
// 	va_list	arg;
// 	int		len = 0;
// 	int		i = -1;

// 	va_start(arg, input);
// 	if (!input)
// 		return (0);
// 	while (input[++i])
// 	{
// 		if (input[i] == '%' && (input[i + 1] == 's' | input[i + 1] == 'd' | input[i + 1] == 'x'))
// 		{
// 			i++;
// 			if (input[i] == 's')
// 				putstr(va_arg(arg, char *), &len);
// 			else if (input[i] == 'd')
// 				putnbr((long long int)va_arg(arg, int), 10, &len);
// 			else if (input[i] == 'x')
// 				putnbr((long long int)va_arg(arg, unsigned int), 16, &len);
// 		}
// 		else
// 			len += write(1, &input[i], 1);
// 	}
// 	va_end(arg);
// 	return (len);
// }

// void	putstr(char *input, int *len)
// {
// 	int	i = -1;

// 	if (!input)
// 	{
// 		*len += write(1, "(null)", 6);
// 		return ;
// 	}
// 	while (input[++i])
// 	{
// 		*len += write(1, &input[i], 1);
// 	}
// }

// void	putnbr(long long int nbr, int base, int *len)
// {
// 	char	*hexa = "0123456789abcdef";

// 	if (nbr < 0)
// 	{
// 		*len += write(1, "-", 1);
// 		nbr *= -1;
// 	}
// 	if (nbr >= base)
// 		putnbr((nbr / base), base, len);
// 	*len += write(1, &hexa[nbr % base], 1);
// }

int	ft_printf(char *input, ...)
{
	int	i = -1;
	int	len = 0;
	va_list arg;

	va_start(arg, input);
	while (input[++i])
	{
		if (input[i] == '%' && (input[i + 1] == 's' || input[i + 1] == 'd' || input[i + 1] == 'x'))
		{
			i++;
			if (input[i] == 's')
				putstr(va_arg(arg, char *), &len);
			else if (input[i] == 'd')
				putnbr((long long int)va_arg(arg, int), 10, &len);
			else if (input[i] == 'x')
				putnbr((long long int)va_arg(arg, unsigned int), 16, &len);
		}
		else
			len += write(1, &input[i], 1);
	}
	va_end(arg);
	return (len);
}

void	putstr(char *input, int *len)
{
	int	i = -1;

	if (!input)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (input[++i])
		*len += write(1, &input[i], 1);
}

void	putnbr(long long int nbr, int base, int *len)
{
	char	*hexa = "0123456789abcdef";

	if (nbr < 0)
	{
		*len += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= base)
		putnbr((nbr / base), base, len);
	*len += write(1, &hexa[nbr % base], 1);
}
