/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:55:37 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/04 10:47:10 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns the middle element in the list
   up to size, and up to max if size = 0*/
int	get_middle(t_list *head, int size)
{

}

/* returns length of linked list */
int	list_size(t_list *head)
{
	t_list	*current;
	int		count;

	if (head == NULL)
		return (0);
	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/* returns the position of the number in
   the linked list */
int	position(t_list *head, int number)
{
	t_list *current;
	int		position;

	if (head == NULL)
		return (0);
	position = 0;
	current = head;
	while (current && current->data != number)
	{
		position++;
		current = current->next;
	}
	return (position);
}
