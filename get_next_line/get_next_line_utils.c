/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:09:02 by fabien            #+#    #+#             */
/*   Updated: 2022/11/16 19:18:53 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_enter(char buffer[BUFFER_SIZE])
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
		if (buffer[i] == '\n')
			return (1);
	return (0);
}

void	list_add(List *root, char buffer[BUFFER_SIZE])
{
	struct List *tmp = root;
	struct List	*newList;
	int			i;

	i = -1;
	newList = malloc(sizeof(struct List));
	if (!newList)
		exit(1);
	while ((++i < BUFFER_SIZE) && buffer[i - 1] != '\n')
	{
		buffer[i] = newList->chain[i];
	}
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newList;
}

char	*list_get(List *root)
{
	struct List	*tmp = root;
	char		*line;
	int	i;
	int	j;

	i = 0;
	j = -1;
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
		while (tmp->chain[++i])
			line[++j] = tmp->chain[i];
		tmp = tmp->next;
	}
	line[++j] = '\0';
	return (line);
}

void	list_free(List *root)
{
	struct List	*tmp;

	while (root != NULL)
	{
		tmp = root;
		root = root->next;
		free(tmp);
	}
}