/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:09:02 by fabien            #+#    #+#             */
/*   Updated: 2022/11/18 13:54:14 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_enter(char buffer[BUFFER_SIZE])
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
		if (buffer[i] == '\n')
			return (i);
	return (0);
}


// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	char	*ptr;

// 	i = -1;
// 	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	while (i <= BUFFER_SIZE)
// 		ptr[i] = s1[i];
// 	i--;
// 	while (s2[++i - ft_strlen(s1)])
// 		ptr[i] = s2[i - ft_strlen(s1)];
// 	ptr[i] = '\0';
// 	return (ptr);
// }


int	list_add(t_Node *root, int fd)
{
	struct t_Node	*tmp;
	int				i;

	tmp = root;
	i = 0;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(struct t_Node));
	if (!tmp->next)
		return (0);
	tmp->next->chain = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp->next->chain)
		return (0);
	i = read(fd, tmp->next->chain, BUFFER_SIZE);
	tmp->next->chain[i + 1] = '\0';
	printf("buffer: %s\n", tmp->next->chain);
	// while ((i < BUFFER_SIZE) && tmp->next->chain[i - 1] != '\n')
	// {
	// 	buffer[i] = tmp->next->chain[i];
	// 	i++;
	// }
	tmp->next->next = NULL;
	return (i - ft_enter(tmp->next->chain));
}


char	*list_get(t_Node *root)
{
	struct t_Node	*tmp;
	char			*line;
	int				i;
	int				j;

	i = 0;
	j = -1;
	tmp = root;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	line = malloc(sizeof(char) * (i * BUFFER_SIZE) + 1);
	if (!line)
		return (NULL);
	tmp = root;
	while (tmp != NULL)
	{
		i = -1;
		while (tmp->chain[++i] && tmp->chain[i] != '\n')
			line[++j] = tmp->chain[i];
		tmp = tmp->next;
	}
	line[++j] = '\0';
	return (line);
}


void	list_free(t_Node *root)
{
	struct t_Node	*tmp;

	while (root != NULL)
	{
		tmp = root;
		root = root->next;
		free(tmp);
	}
}