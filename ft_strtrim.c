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


static int	counting_set(char const *s, char const *set, int len)
{
	int	i;

	i = 0;
	while (s[len] == set[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	start = counting_set(s1, set);
	end = counting_set(s1, set);
	ptr = malloc((ft_strlen(s1) - (start + end) + 1) * sizeof(char));
	// while()
}