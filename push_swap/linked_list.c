/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:43 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/18 14:50:45 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  add the integer to the end
	of the linked list using malloc */
void	add_int(t_list *head, int nb)
{
	t_list	*new_node;
	t_list	*current;

	current = get_last(head);
	new_node = malloc(sizeof(t_list));
	new_node->data = nb;
	new_node->flag = 0;
	new_node->next = NULL;
	new_node->previous = current;
	if (!head)
		head = new_node;
	else
		current->next = new_node;
	// ft_printf("%d\n", new_node->data);
}

/* gets the first element of the linked list */
t_list	*get_first(t_list *head)
{
	t_list	*first;

	if (!head)
		return(head);
	first = head;
	return (first);
}

/* gets last element of the linked list */
t_list	*get_last(t_list *head)
{
	t_list	*last;

	if (!head)
		return (head);
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

		free(current);
	}
	head = NULL;
}

/* checks if head exists, returns true
	if it does, false otherwise */
int	check_head(t_list *head)
{
	if (head == 0)
		return (0);
	return (1);
}
