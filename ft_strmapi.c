/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:28:57 by fabien            #+#    #+#             */
/*   Updated: 2022/11/02 14:03:33 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;

	ptr = malloc(ft_strlen(s) * sizeof(s));
	while(s[++i])
		(*f)(i, s[i]);
	return ((char *)s);
}