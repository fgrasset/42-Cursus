/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:32:17 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/06 13:30:18 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int wordcount(char const *s, char c)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	if (s[0] == c)
		word--;	
	while (s[++i])
		if (s[i] == c && s[i + 1] != c)
			word++;
	return (word);
}

static char	*wordcreate(int start, int end, char const *s)
{
	char	*word;
	int		i;
	
	i = 0;
	word = malloc((end - start + 2) * sizeof(char));
	if (!word)
		return (NULL);
	while (start <= end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		wplace;

	tab = malloc((wordcount(s, c) + 1) * sizeof(char *));
	i = 0;
	wplace = -1;
	while (s[i])
	{
		j = 0;
		while (s[i + j] != c)
		{
			if (s[(i + j) + 1] == c)
				tab[++wplace] = wordcreate(i, i + j, s);
			j++;
		}
		i += j;
		i++;
	}
	tab[++wplace] = (NULL);
	return (tab);
}

// int	main()
// {
// 	char *s = "                  olol";
// 	char **tab = ft_split(s, ' ');
// 	for(int i=0; i<=1; i++) {
//          printf("%s\n", tab[i]);
// 	}
// }