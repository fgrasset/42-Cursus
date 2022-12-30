/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:43 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/30 10:20:17 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  add the integer to the end
	of the linked list using malloc */
void	add_int(t_list *head, int nb)
{
	t_list	*new_node;
	t_list	*current;

	if (check_head(head))
		current = get_last(head);
	new_node = malloc(sizeof(t_list));
	new_node->data = malloc(sizeof(int) * 1);
	new_node->data = nb;
	new_node->flag = 0;
	new_node->next = NULL;
	new_node->previous = current;
	if (current == head)
		new_node->previous = NULL;
	current->next = new_node;
}

/* gets the first element of the linked list */
t_list	*get_first(t_list *head)
{
	t_list	*first;

	if (check_head(head))
		first = head;
	return (first);
}

/* gets last element of the linked list */
t_list	*get_last(t_list *head)
{
	t_list	*last;

	if (check_head(head))
		last = head;
	while (last)
		last = last->next;
	return (last);
}

/*frees list entirely */
void	list_free(t_list *head)
{
	t_list	*current;
	t_list	*stock;

	stock = head;
	while (stock != NULL)
	{
		current = stock;
		stock = stock->next;
		free(current->data);
		free(current);
	}
	head = NULL;
	return (NULL);
}

/* checks if head exists, returns true
	if it does, false otherwise */
int	check_head(t_list *head)
{
	if (head == 0)
		return (0);
	return (1);
}
