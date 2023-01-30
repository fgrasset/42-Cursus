/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:43 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/30 09:33:19 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  add the integer to the end
	of the linked list using malloc */
void	add_int(t_list **head, int nb)
{
	t_list	*new_node;
	t_list	*current;

	new_node = (t_list *) malloc(sizeof(t_list));
	new_node->data = nb;
	new_node->index = index_calcuation(head, new_node->data);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = get_last(*head);
	current->next = new_node;
}

/* returns last element of the linked list */
t_list	*get_last(t_list *head)
{
	t_list	*last;

	if (!head)
		return (NULL);
	last = head;
	while (last->next)
		last = last->next;
	return (last);
}

/*frees list entirely */
void	list_free(t_list **head)
{
	t_list	*current;
	t_list	*stock;

	stock = *head;
	while (stock != NULL)
	{
		current = stock;
		stock = stock->next;
		free(current);
	}
	*head = NULL;
}
