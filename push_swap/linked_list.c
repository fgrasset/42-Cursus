/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:43 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/19 16:08:46 by fgrasset         ###   ########.fr       */
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
	new_node->flag = 0;
	new_node->next = NULL;
	new_node->previous = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = get_last(*head);
	printf("current next: %d\n", current->data);
    current->next = new_node;
	write(1, "test", 4);
    new_node->previous = current;
	// else
	// {
	// 	head->previous = new_node;
	// 	current->next = new_node;
	// }
	// ft_printf("This is the new_node: %d\n", ->data);
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
