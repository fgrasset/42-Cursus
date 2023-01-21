/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:54:59 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/21 13:57:24 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swaps first 2 elements top of list A */
void	sa(t_list **head_a)
{
	t_list	*ele1;
	t_list	*ele2;

	ele1 = *head_a;
	ele2 = (*head_a)->next;
	if (!ele1 || !ele2)
		return ;
	ele2->previous = ele1->previous;
	ele1->next = ele2->next;
	ele2->next = ele1;
	ele1->previous = ele2;
	*head_a = ele2;
	ft_printf("sa\n");
}

/* swaps first 2 elements top of list B */
void	sb(t_list **head_b)
{
	t_list	*ele1;
	t_list	*ele2;

	ele1 = *head_b;
	ele2 = (*head_b)->next;
	if (!ele1 || !ele2)
		return ;
	ele2->previous = ele1->previous;
	ele1->next = ele2->next;
	ele2->next = ele1;
	ele1->previous = ele2;
	*head_b = ele2;
	ft_printf("sb\n");
}

/* executes sa and sb */
void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
	ft_printf("ss\n");
}

/* puts first element of list B and puts it
   on top of list A, returns if list
   A is NULL */
void	pa(t_list **head_a, t_list **head_b)
{
	// t_list	*ele_a;
	// t_list	*ele_b;

	// // if (!head_a || !head_b)
	// // 	return ;
	// ele_a = *head_a;
	// ele_b = *head_b;
	// *head_b = ele_b->next;
	// ele_b->next->previous = ele_b->previous;
	// ele_b->next = ele_a;
	// ele_b->previous = get_last(head_a);
	// ele_a->previous = ele_b;
	// *head_a = ele_b;
	// ft_printf("pa\n");
	t_list	*ele_b;

	if(*head_b)
	{
		ele_b = *head_b;
		*head_b = ele_b->next;
		if (*head_b)
			(*head_b)->previous = NULL;
		ele_b->previous = NULL;
		ele_b->next = *head_a;
		if (*head_a)
			(*head_a)->previous = ele_b;
		*head_a = ele_b;
		ft_printf("pa\n");
	}
}

/* puts first element of list A and puts it
   on top of list B, returns if list
   B is NULL */
void	pb(t_list **head_b, t_list **head_a)
{
	// t_list	*ele_a;
	// t_list	*ele_b;

	// ele_a = *head_a;
	// ele_a->next->previous = ele_a->previous;
	// if (!head_b)
	// {
	// 	*head_b = ele_a;
	// 	*head_a = ele_a->next;
	// 	ele_a->next = NULL;
	// 	ele_a->previous = ele_a;
	// 	write(1, "head", 4);
	// 	return ;
	// }
	// ele_b = *head_b;
	// *head_a = ele_a->next;
	// ele_a->next = ele_b;
	// ele_a->previous = ele_b->previous;
	// write(1, "haha", 4);
	// *head_b = ele_a;
	// ele_b->previous = ele_a;
	// ft_printf("pb\n");
	t_list *ele_a;

	if (*head_a)
	{
		ele_a = *head_a;
		*head_a = ele_a->next;
		if (*head_a)
			(*head_a)->previous = NULL;
		ele_a->previous = NULL;
		ele_a->next = *head_b;
		if (*head_b)
			(*head_b)->previous = ele_a;
		*head_b = ele_a;
		ft_printf("pb\n");
}
}
