/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/08 16:53:31 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_Node	*head;
	char			*line;
	int				reading;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	reading = 1;
	while (reading != 0 && !enter(&head))
	{
		reading = list_add(&head, fd);
		if (reading == -1)
		{
			list_free(&head);
			return NULL;
		}
	}
	line = malloc(sizeof(char) * (list_len(&head) + 1));
	if (!line)
		return (NULL);
	ft_bzero(line, list_len(&head) + 1);
	list_get(&head, line);
	stash_make(&head);
	if (line[0] == '\0')
	{
		list_free(&head);
		free(line);
		return (NULL);
	}
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
	if (!stash)
	{
		free(stash);
		return ;
	}
	i = 0;
	j = 0;
	while (current->next != NULL)
		current = current->next;	
	while (current->buffer[i] && current->buffer[i] != '\n')
		i++;
	if (current->buffer[i] && current->buffer[i] == '\n')
		i++;
	stash->buffer = malloc(sizeof(char) * (BUFFER_SIZE - i) + 1);
	if (!stash->buffer)
	{
		free(stash->buffer);
		free(stash);
		return ;
	}
	while (current->buffer[i])
		stash->buffer[j++] = current->buffer[i++];
	stash->buffer[j] = '\0';
	stash->next = NULL;
	list_free(head);
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

// int	main()
// {
// 	int	fd = open("file.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }