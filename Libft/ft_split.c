/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:32:17 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/07 16:05:03 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
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

static void	*timetofree(char **tab, int wplace)
{
	while (wplace > 0)
		free(tab[--wplace]);
	free(tab);
	return (NULL);
}

// static void	initvar(char **tab, int i, int j, int wplace)
// {
// 	**tab;
// 	i = 0;
// 	j;
// 	wplace;
// }

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		wplace;

	tab = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	wplace = -1;
	while (s[i])
	{
		j = 0;
		while (s[j + i] && s[i + j] != c)
		{
			if (s[i + j + 1] == '\0' || s[(i + j) + 1] == c)
				tab[++wplace] = wordcreate(i, i + j, s);
			if (s[i + j + 1] == '\0' || s[(i + j) + 1] == c)
				if (tab[wplace] == (NULL))
					return (timetofree(tab, wplace));
			j++;
		}
		i += j;
		if (s[i] != '\0')
			i++;
	}
	tab[++wplace] = (NULL);
	return (tab);
}
