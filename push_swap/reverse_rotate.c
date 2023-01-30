/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:55:24 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/30 09:13:58 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* last element of stack A becomes first
   and all the elements go down one place */
void	rra(t_list **head_a)
{
	t_list	*last;
	t_list	*pre_last;
	t_list	*first;

	last = get_last(*head_a);
	first = *head_a;
	pre_last = *head_a;
	while (pre_last->next != last)
		pre_last = pre_last->next;
	pre_last->next = NULL;
	last->next = first;
	*head_a = last;
	ft_printf("ra\n");
}
