/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:55:24 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/20 11:08:52 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* last element of stack A becomes first
   and all the elements go down one place */
void	rra(t_list **head_a)
{
	t_list	*first;
	t_list	*last;
	t_list	*pre_last;

	first = *head_a;
	last = get_last(head_a);
	pre_last = last->previous;
	head_a = &last;
	pre_last->next = NULL;
	last->previous = pre_last;
	last->next = first;
	first->previous = last;
	ft_printf("rra\n");
}

/* last element of stack B becomes first
   and all the elements go down one place */
void	rrb(t_list **head_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*pre_last;

	first = *head_b;
	last = get_last(head_b);
	pre_last = last->previous;
	head_b = &last;
	pre_last->next = NULL;
	last->previous = pre_last;
	last->next = first;
	first->previous = last;
	ft_printf("rrb\n");
}

/* executes rra and rrb */
void	rrr(t_list **head_a, t_list **head_b)
{
	rra(head_a);
	rrb(head_b);
	ft_printf("rrr\n");
}
