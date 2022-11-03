/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:12:51 by fabien            #+#    #+#             */
/*   Updated: 2022/11/03 16:36:22 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checking_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if ((int)c == (int)set[i])
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
	ptr = malloc((ft_strlen(s1) - (i + end) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while(s1[i] && i < end)
	{
		printf("voici le i : %d et le j : %d\n", i, j);
		ptr[j] = s1[i];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int	main()
{
	printf("%s", ft_strtrim("aaacecie est le test eeaa", "aec"));
}