/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:55:13 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/28 12:47:21 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* first element of stack A becomes last
   and all the others gain one place */
void	ra(t_list **head_a)
{
	t_list	*last;
	t_list	*second;
	t_list	*first;

	second = (*head_a)->next;
	last = get_last(*head_a);
	first = *head_a;

	last->next = first;
	last->next->next = NULL;
	*head_a = second;
	ft_printf("ra\n");
}
