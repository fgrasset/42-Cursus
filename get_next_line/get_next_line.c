/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/11 21:41:57 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_Node	*head;
	char			*line;
	int				reading;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (return_error(&head, 1, line));
	reading = 1;
	while (!enter(&head) && reading != 0)
	{
		reading = list_add(&head, fd);
		if (reading == -1)
			return (list_free(&head, 1));
	}
	line = malloc(sizeof(char) * (list_len(&head) + 1));
	if (!line)
		return (NULL);
	ft_bzero(line, list_len(&head) + 1);
	list_get(&head, line);
	stash_make(&head);
	if (line[0] == '\0')
		return (return_error(&head, 2, line));
	return (line);
}

/* makes a new node of what is after the \n 
 and deletes the previous nodes */
void	stash_make(t_Node **head)
{
	t_Node	*current;
	t_Node	*stash;
	int		i;
	int		j;

	current = *head;
	stash = malloc(sizeof(t_Node));
	i = 0;
	j = 0;
	while (current->next != NULL)
		current = current->next;
	while (current->buffer[i] && current->buffer[i] != '\n')
		i++;
	if (current->buffer[i] && current->buffer[i] == '\n')
		i++;
	stash->buffer = malloc(sizeof(char) * (BUFFER_SIZE - i) + 1);
	if (!stash || !stash->buffer || current == NULL)
		return (free(stash));
	while (current->buffer[i])
		stash->buffer[j++] = current->buffer[i++];
	stash->buffer[j] = '\0';
	stash->next = NULL;
	list_free(head, 0);
	*head = stash;
}

/* basically bzero but made by hand */
void	ft_bzero(void *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

char	*return_error(t_Node **head, int flag, char *line)
{
	if (flag == 1)
	{
		line = list_free(head, 1);
		head = NULL;
		return (NULL);
	}
	else if (flag == 2)
	{
		free(line);
		return (list_free(head, 1));
	}
	return (NULL);
}
