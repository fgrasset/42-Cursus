/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:09:02 by fabien            #+#    #+#             */
/*   Updated: 2022/12/01 15:13:57 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* reads BUFFER_SIZE elements and adds them to a buffer
returns 0 if buffer contains /n, number otherwise
or -1 if issue */
int	list_add(t_Node **head, int fd)
{
	t_Node	*new_node;
	t_Node	*current;
	int		read_neg;

	new_node = malloc(sizeof(t_Node));
	new_node->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new_node || !new_node->buffer)
		return (0);
	current = *head;
	new_node->next = NULL;
	read_neg = read(fd, new_node->buffer, BUFFER_SIZE);
	if ((current == NULL && read_neg == 0) || read_neg == -1)
	{
		free(new_node->buffer);
		free(new_node);
		return(-1);
	}
	new_node->buffer[read_neg] = '\0';
	if (*head == NULL)
	{
		*head = new_node;
		return (read_neg);
	}
	while (current != NULL)
		current = current->next;
	current = new_node;
	printf("new_node buffer: %s\n", current->buffer);
	printf("read value: %d\n", read_neg);
	return (read_neg);
}

/* returns the length of all the buffers in the linked list */
int	list_len(t_Node **head)
{
	t_Node	*current;
	int		len;
	int		i;

	len = 0;
	current = *head;
	while (current)
	{
		i = 0;
		while (current->buffer[i])
		{
			if(current->buffer[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		current = current->next;
	}
	return (len);
}

/* fills res with contents of buffer in the linked lists until the \n */
void	list_get(t_Node **head, char *line)
{
	t_Node	*current;
	int		i;

	if (*head == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		i = 0;
		while (current->buffer[i] != '\0')
		{
			line[i] = current->buffer[i];
			if (current->buffer[i] == '\n')
				return ;
			// printf("line[%d]: %c and current.buffer[%d]: %c\n", j, line[j], i, current->buffer[i]);
			i++;
		}
		current = current->next;
	}
}

/* frees the linked list entirely */
void	list_free(t_Node **head)
{
	t_Node	*current;
	t_Node	*stock;

	stock = *head;
	while (stock != NULL)
	{
		current = stock;
		stock = stock->next;
		free(current->buffer);
		free(current);
	}
}

/* returns 0 if \n is in the buffer, n otherwise */
int	enter(t_Node **head)
{
	t_Node	*current;
	int		i;

	i = 0;
	if (*head == NULL)
		return (1);
	current = *head;
	while (current->next != NULL)
		current = current->next;
	// if (string == NULL)
	// 	return (1);
	// if (string[0] == '\0')
	// 	return (1);
	printf("string: %s\n", current->buffer);
	while (current->buffer[i])
	{
		if (current->buffer[i] == '\n')
			return (0);
		i++;
	}
	return (i);
}
