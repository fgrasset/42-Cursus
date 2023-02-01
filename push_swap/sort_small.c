/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:49:48 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/30 20:16:17 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns position of the demanded index in the list */
int	position(t_list *head, int nb)
{
	t_list	*current;
	int		pos;

	current = head;
	pos = 0;
	while (current)
	{
		if (current->index == nb)
			return (pos);
		pos++;
		current = current->next;
	}
	return (0);
}

/* sorting algorithm for 3 numbers */
void	sort_3(t_list **head)
{
	print_list_index(*head);
	printf("head.index: %d\nhead.next.index: %d\n", (*head)->index, (*head)->next->index);
	if (isordered(*head))
		return ;
	if ((*head)->index == 0 && (*head)->next->index == 2)
	{
		sa(head);
		ra(head);
	}
	else if ((*head)->index == 1 && (*head)->next->index == 0)
		sa(head);
	else if ((*head)->index == 1 && (*head)->next->index == 2)
		rra(head);
	else if ((*head)->index == 2 && (*head)->next->index == 1)
	{
		ra(head);
		sa(head);
	}
	else if ((*head)->index == 2 && (*head)->next->index == 0)
		ra(head);
}

/* sorting algorithm for 4 numbers */
void	sort_4(t_list **head_a, t_list **head_b)
{
	t_list	*current;

	if (position(*head_a, 0) < 2)
	{
		while ((*head_a)->index != 0)
			ra(head_a);
	}
	else
	{
		while ((*head_a)->index != 0)
			rra(head_a);
	}
	pb(head_b, head_a);
	current = *head_a;
	while (current)
	{
		current->index -= 1;
		current = current->next;
	}
	sort_3(head_a);
	pa(head_a, head_b);
}

/* sorting algorithm for 5 numbers */
void	sort_5(t_list **head_a, t_list **head_b)
{
	t_list	*current;

	current = *head_a;
	if (position(*head_a, 0) < 3)
	{
		while ((*head_a)->index != 0)
			ra(head_a);
	}
	else
	{
		while ((*head_a)->index != 0)
			rra(head_a);
	}
	pb(head_b, head_a);
	current = *head_a;
	while (current)
	{
		current->index -= 1;
		current = current->next;
	}
	sort_4(head_a, head_b);
	pa(head_a, head_b);
}
