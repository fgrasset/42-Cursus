/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:49:48 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/28 14:41:26 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting algorithm for 3 numbers */
void	sort_3(t_list **head)
{
	if (isordered(*head))
		return ;
	if ((*head)->index == 0 & (*head)->next->index == 2)
	{
		sa(head);
		rra(head);
	}
	else if ((*head)->index == 1 & (*head)->next->index == 0)
		sa(head);
	else if ((*head)->index == 1 & (*head)->next->index == 2)
		rra(head);
	else if ((*head)->index == 2 & (*head)->next->index == 1)
	{
		ra(head);
		sa(head);
	}
	else if ((*head)->index == 2 & (*head)->next->index == 0)
		ra(head);
}

/* sorting algorithm for 4 numbers */
void	sort_4(t_list **head_a, t_list **head_b)
{
	t_list	*current;

	while ((*head_a)->index != 0)
		ra(head_a);
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

	while ((*head_a)->index != 0)
		ra(head_a);
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
