/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/28 13:57:48 by fgrasset         ###   ########.fr       */
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
	// if (!stash)
	// {	
	// 	stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// 	stash[0] = '\0';
	// }
	end = 0;
	while (end == 0)
		end = list_add(&head, fd);
	if (end == -1 || (end == 0 && stash == NULL))
		return NULL;
	line = malloc(sizeof(char) * (list_len(&head) + 1));
	if (!line)
		return (NULL);
	ft_bzero(line, list_len(&head) + 1);
	print_list(&head);
	stash_make(&head);
	// write(1,"test",4);
	// stash_get(stash, line);
	// stash_fill(&head, stash);
	list_get(&head, line);
	// list_free(&head);
	printf("line: %s\n", line);
	return (line);
}


/*fills stash with elements after the \n in last buffer of linked list*/
// void	stash_fill(t_Node **head, char *stash)
// {
// 	t_Node	*current;
// 	int		count;
// 	int		i;

// 	if (*head == NULL)
// 		return ;
// 	current = *head;
// 	count = 0;
// 	while (current->next != NULL)
// 		current = current->next;
// 	printf("current.buffer[%d]: %c\n", count, current->buffer[count]);
// 	while (current->buffer[count] && current->buffer[count] != '\n')
// 		count++;
// 	i = -1;
// 	printf("current.buffer[%d]: %c\n", count, current->buffer[count]);
// 	while (current->buffer[count] != '\0')
// 	{
// 		stash[++i] = current->buffer[count];
// 		count++;
// 	}
// 	write(1,"stash_fill", 10);
// 	stash[++i] = '\0';
// }

/*get last node and removes what is before /n*/
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
	printf("stash: %s\n", stash->buffer);
	list_free(head);
	*head = stash;
}

/*fills res with the stash from \n to the end*/
// void	stash_get(char *stash, char *line)
// {
// 	int	j;

// 	if (!stash)
// 	{	
// 		stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 		stash[0] = '\0';
// 	}
// 	j = -1;
// 	// if (stash[0] == '\0')
// 	// 	return ;
// 	while (stash[++j])
// 		line[j] = stash[j];
// 	line[j] = '\0';
// }

/*basically bzero but made by hand*/
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