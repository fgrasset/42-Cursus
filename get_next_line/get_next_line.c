/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/30 14:17:30 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_list(t_Node **head)
{
	t_Node *current;

	current = *head;
	while (current)
	{
		printf("current.buffer: %s\n", current->buffer);
		current = current->next;
	}
}


char	*get_next_line(int fd)
{
	static char		*stash;
	static t_Node	*head;
	char			*line;
	int				end;

	if (fd == 0 || BUFFER_SIZE == 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	head = NULL;
	end = 1;
	while (enter(&head) || end != 0)
	{
		end = list_add(&head, fd);
		printf("end : %d\n", end);
		write(1, "test", 4);
	}
	if (end == -1 || (end == 0 && stash == NULL))
		return NULL;
	line = malloc(sizeof(char) * (list_len(&head) + 1));
	if (!line)
		return (NULL);
	ft_bzero(line, list_len(&head) + 1);
	// print_list(&head);
	list_get(&head, line);
	stash_make(&head);
	// list_free(&head);
	// printf("line: %s\n", line);
	return (line);
}

/* makes a new node of what is after the \n */
void	stash_make(t_Node **head)
{
	t_Node	*current;
	t_Node	*stash;
	int		i;
	int		j;

	current = *head;
	stash = malloc(sizeof(t_Node));
	if (!stash)
		return ;
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
		return ;
	while (current->buffer[i])
		stash->buffer[j++] = current->buffer[i++];
	stash->buffer[j] = '\0';
	stash->next = NULL;
	// printf("stash: %s\n", stash->buffer);
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

int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}