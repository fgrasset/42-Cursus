/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:12:51 by fabien            #+#    #+#             */
/*   Updated: 2022/11/01 21:07:02 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	checking_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		i;
	int		j;
	char	*ptr;

	i = ft_strlen(s1);
	end = 0;
	j = 0;
	while (i >= 0 && checking_set(s1[i], set))
	{
		end++;
		i--;
	}
	i = 0;
	while(s1[i] && checking_set(s1[i], set))
		i++;
	printf("%d ' ' %d", end, i);
	ptr = malloc((ft_strlen(s1) - (i + end) + 3) * sizeof(char));
	while(s1[i] && i <= end)
	{
		ptr[j] = s1[i];
		ptr++;
		j++;
	}
	return (ptr);
}

int	main()
{
	printf("%s", ft_itoa(5603));
}