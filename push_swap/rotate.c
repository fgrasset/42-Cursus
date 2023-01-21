/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:55:13 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/21 19:00:05 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// t_list	*last;
// t_list	*first;

// first = *head_a;
// last = get_last(head_a);
// if (!last || !first)
// 	return ;
// head_a = &first->next;
// (*head_a)->previous = first;
// first->previous = last;
// first->next = NULL;
// last->next = first;

/* first element of stack A becomes last
   and all the others gain one place */
void	ra(t_list **head_a)
{
	t_list	*last;

	last = get_last(head_a);
	last->next = *head_a;
	(*head_a)->next->previous = last;
	(*head_a)->previous = (*head_a)->next;
	*head_a = (*head_a)->next;
	last->next->next = NULL;
	ft_printf("ra\n");
}
/* first element of stack B becomes last
   and all the others gain one place */
void	rb(t_list **head_b)
{
	t_list	*last;
	t_list	*first;

	first = *head_b;
	last = get_last(head_b);
	if (!last || !first)
		return ;
	head_b = &first->next;
	(*head_b)->previous = first;
	first->previous = last;
	first->next = NULL;
	last->next = first;
	ft_printf("rb\n");
}

/* executes ra and rb */
void	rr(t_list **head_a, t_list **head_b)
{
	ra(head_a);
	rb(head_b);
	ft_printf("rr\n");
}
