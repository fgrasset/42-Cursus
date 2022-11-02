/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:31:57 by fabien            #+#    #+#             */
/*   Updated: 2022/10/31 20:31:57 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_power(int power)
{
	int	res;

	res = 10;
	if (power == 0)
		return (1);
	while (power > 0)
	{
		res *= 10;
		power--;
	}
	return (res);
}

static int	check_power(int n)
{
	int	i;

	i = 0;
	while (n >= ft_power(i))
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		j;
	int		pow;
	char	*res;

	j = 0;
	pow = check_power(n);

	if (n == -2147483648)
	{
		res = "-2147483648";
		return (res);
	}
	res = malloc((pow + 1) * sizeof(char));
	if(!res)
		return(NULL);
	if (n < 0)
	{
		j = -1;
		res[++j] = '-';
	}
	
	while (n > 9)
	{
		res[++j] = (char)(n / ft_power(pow));
		n /= ft_power(pow);
		pow--;
	}
	res[j] = (char)n;
	return (res);
}
