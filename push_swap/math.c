/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:50:01 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/30 14:45:54 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* normalize the list between 0 and 1
   if flag == 1 unormalize it otherwise */
void	normalize(t_list *head, int flag)
{
	static int	max;
	static int	min;
	t_list		*current;

	if (!head)
		return ;
	current = head;
	if (!max && !min)
	{
		max = max_min(head, 1);
		min = max_min(head, 0);
		if (min == max)
			return ;
	}
	while (current)
	{
		if (flag == 0)
			current->data = (current->data - min) / (max - min);
		else
			current->data = (current->data * (max - min)) + min;
		current = current->next;
	}
}

/* returns max of list if flag == 1,
   returns min if flag == 0 */
int	max_min(t_list *head, int flag)
{
	int	 	result;
	int		tmp;
	t_list	*current;

	result = 0;
	tmp = 0;
	while (current)
	{
		if (flag == 0)
		{
			tmp = 1;
			if (current->data < tmp)
				tmp = current->data;
		}
		else
		{
			if (current->data > tmp)
				tmp = current->data;
		}
		current = current->next;
	}
	return (tmp);
}
