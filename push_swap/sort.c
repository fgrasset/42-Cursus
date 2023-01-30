/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:35:59 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/30 09:34:46 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns the index of the number and actualize the others */
int	index_calcuation(t_list **head, int nb)
{
	t_list	*current;
	int		i;

	i = 0;
	if (!head)
		return (0);
	current = *head;
	while (current)
	{
		if (current->data > nb)
			current->index += 1;
		else
			i++;
		current = current->next;
	}
	return (i);
}

/* returns true if numbers needs to be pushed
   meaning that the bit == 0 */
int	to_push(int nb, int i)
{
	if ((nb >> i) & 1)
		return (0);
	return (1);
}

/* returns true if list is ordered */
int	isordered(t_list *head)
{
	t_list	*current;
	int		min;

	current = head;
	min = 0;
	while (current)
	{
		if (current->index != min)
			return (0);
		++min;
		current = current->next;
	}
	return (1);
}

/* sorting algorithm */
void	sort(t_list **head_a, t_list **head_b)
{
	static int	bit_position;
	t_list		*current;
	int			size;
	int			i;

	while (!isordered(*head_a))
	{
		size = list_size(*head_a);
		i = -1;
		while (++i < size)
		{
			current = *head_a;
			if (to_push(current->index, bit_position))
				pb(head_b, head_a);
			else
				ra(head_a);
		}
		size = list_size(*head_b);
		while (--size >= 0)
			pa(head_a, head_b);
		++bit_position;
	}
}
