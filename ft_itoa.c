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

	res = 1;
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
	while (n > 9)
	{
		n /= 10;
		i++;
	}
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
	res = (char *)malloc((pow + 3) * sizeof(char));
	if(!res)
		return(NULL);
	if (n < 0)
	{
		res[j] = '-';
		j++;
	}
	
	while (n > 9)
	{
		res[j] = (n / ft_power(pow)) + '0';
		//printf("res at %d is %c\n", j, res[j]);
		n = n % ft_power(pow);
		//printf("and n is %d\n", n);
		j++;
		pow--;
	}
	res[j] = n + '0';
	res[j + 1] = '\0';
	return (res);
}

// int	main()
// {
// 	int	i;
// 	char	*ptr;

// 	i = 99999;
// 	ptr = ft_itoa(i);
// 	printf("%s", ptr);
// 	free(ptr);
// }
