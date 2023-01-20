/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:35:59 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/20 13:36:17 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting algorithm doing both stack at once */
void	sort(t_list **head_a, t_list **head_b)
{
	int	max_a;
	int	min_a;
	int	max_b;
	int	min_b;

	max_a = get_max(*head_a);
	min_a = get_min(*head_a);
	max_b = get_max(*head_b);
	min_b = get_min(*head_b);
	while ((*head_a)->data != min_a && (*head_a)->previous->data != max_a)
	{
		if ((*head_a)->next->data < (*head_a)->data && (*head_a)->data != max_a)
				actions("sa", 'A');
		actions ("ra", 'A');
	}
	while ((*head_b)->data != min_b && (*head_b)->previous->data != max_b)
	{
		if ((*head_b)->next->data < (*head_b)->data && (*head_b)->data != max_b)
				actions("sb", 'B');
		actions ("rb", 'B');
	}
	combine(actions("", 'C'), head_a, head_b);
}

/* stocks the actions to perform, put them in A or B
   depending on parameter stack (A, B)
   if stack == C returns the list of actions */
char	***actions(char *str, char stack)
{
	static char	***actions;
	static int	index_a;
	static int	index_b;
	int			i;

	if (stack == 'A')
	{
		i = -1;
		while (str[++i])
		{
			actions[0][1][i] = str[i];
		}
		index_a++;
	}
	else if (stack == 'B')
	{
		i = -1;
		while (str[++i])
		{
			actions[1][1][i] = str[i];
		}
		index_b++;
	}
	else
	{
		return (actions);
	}
	return (NULL);
}

/* combines the actions and executes them */
void	combine(char ***actions, t_list **head_a, t_list **head_b)
{
	static int j;

	while (actions[0][1][j] && actions[1][1][j])
	{
		if (ft_strcmp(&actions[0][1][j], "sa") && ft_strcmp(&actions[1][1][j], "sb"))
			ss(head_a, head_b);
		else if (ft_strcmp(&actions[0][1][j], "ra") && ft_strcmp(&actions[1][1][j], "rb"))
			rr(head_a, head_b);
		else if (ft_strcmp(&actions[0][1][j], "rra") && ft_strcmp(&actions[1][1][j], "rrb"))
			rrr(head_a, head_b);
		else
		{
			if (ft_strcmp(&actions[0][1][j], "sa"))
				sa(head_a);
			else if (ft_strcmp(&actions[0][1][j], "ra"))
				ra(head_a);
			else if (ft_strcmp(&actions[0][1][j], "pb"))
				pb(head_a, head_b);
			if (ft_strcmp(&actions[1][1][j], "sb"))
				sb(head_b);
			else if (ft_strcmp(&actions[1][1][j], "rb"))
				rb(head_b);
			else if (ft_strcmp(&actions[1][1][j], "pa"))
				pa(head_a, head_b);
		}
		j++;
	}
}
