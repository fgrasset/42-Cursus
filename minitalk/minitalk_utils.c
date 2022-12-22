/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:27:23 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/22 15:00:44 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct t_node  
{
	char			data;
	struct t_node	*next;
} t_node;

/* returns the last element of the linked list */
t_node	*get_last(t_node *head)
{
	t_node	*current;

	if (!head)
		return NULL;

	current = head;
	while(current)
	{
		current = current->next;
	}
	return current;
}

/* adds en alement at the end of the list */a
void	add_element(t_node *head, char data)
{
	t_node	*current;
	t_node	*newnode;

	if (!head)
		return NULL;	
	current = get_last(head);
	newnode = malloc(sizeof(char) * 1);
	if (!newnode)
		return NULL;
	newnode->data = data;
	newnode->next =NULL;
	current = current->next;
	current = newnode;
}

/* frees the entire linked list */
void	free_list(t_node *head)
{
	t_node	*current;
	t_node	*stock;

	stock = head;
	while (stock != NULL)
	{
		current = stock;
		stock = stock->next;
		free(current->data);
		free(current);
	}
	head = NULL;
}
