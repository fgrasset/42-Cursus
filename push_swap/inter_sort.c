/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:04:53 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/04 11:36:23 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inter_sort(t_list *head, int len)
{
	t_list	*current;
	t_l		*list;

	current = head;
	list->count = 0;
	list->max = max_min(head, 1, len);
	list->min = max_min(head, 0, len);
	list->max_pos = position(head, list->max);
	list->min_pos = position(head, list->min);
	if (list->max_pos < list->min_pos && list->max_pos < len / 4)
}
