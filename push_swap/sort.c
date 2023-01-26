/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:35:59 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/26 16:46:39 by fgrasset         ###   ########.fr       */
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
	return	(i);
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
	return(1);
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
		current = *head_a;
		sleep(1);
		write(1, "---------------\n", 16);
		write(1, "list A: ", 8);
		print_list(*head_a);
		while (++i < size)
		{
			current = *head_a;
			if (to_push(current->index, bit_position))
				pb(head_b, head_a);
			else
				ra(head_a);
			current = current->next;
		}
		size = list_size(*head_b);
		write(1, "list B: ", 8);
		print_list(*head_b);
		while (--size >= 0)
		{
			pa(head_a, head_b);
		}
		write(1, "test", 4);
		++bit_position;
		printf("bit_positioin: %d\n", bit_position);
	}
}

// /* sorting algorithm doing both stack at once */
// void	sort(t_list **head_a, t_list **head_b)
// {
// 	int	max_a;
// 	int	min_a;
// 	int	max_b;
// 	int	min_b;

// 	max_a = get_max(*head_a);
// 	min_a = get_min(*head_a);
// 	max_b = get_max(*head_b);
// 	min_b = get_min(*head_b);
// 	while ((*head_a)->data != min_a && (*head_a)->previous->data != max_a)
// 	{
// 		if ((*head_a)->next->data < (*head_a)->data && (*head_a)->data != max_a)
// 				actions("sa", 'A');
// 		actions ("ra", 'A');
// 	}
// 	while ((*head_b)->data != min_b && (*head_b)->previous->data != max_b)
// 	{
// 		if ((*head_b)->next->data < (*head_b)->data && (*head_b)->data != max_b)
// 				actions("sb", 'B');
// 		actions ("rb", 'B');
// 	}
// 	combine(actions("", 'C'), head_a, head_b);
// }

// /* stocks the actions to perform, put them in A or B
//    depending on parameter stack (A, B)
//    if stack == C returns the list of actions */
// char	***actions(char *str, char stack)
// {
// 	static char	***actions;
// 	static int	index_a;
// 	static int	index_b;
// 	int			i;

// 	if (stack == 'A')
// 	{
// 		i = -1;
// 		while (str[++i])
// 		{
// 			actions[0][1][i] = str[i];
// 		}
// 		index_a++;
// 	}
// 	else if (stack == 'B')
// 	{
// 		i = -1;
// 		while (str[++i])
// 		{
// 			actions[1][1][i] = str[i];
// 		}
// 		index_b++;
// 	}
// 	else
// 	{
// 		return (actions);
// 	}
// 	return (NULL);
// }

// /* combines the actions and executes them */
// void	combine(char ***actions, t_list **head_a, t_list **head_b)
// {
// 	static int j;

// 	while (actions[0][1][j] && actions[1][1][j])
// 	{
// 		if (ft_strcmp(&actions[0][1][j], "sa") && ft_strcmp(&actions[1][1][j], "sb"))
// 			ss(head_a, head_b);
// 		else if (ft_strcmp(&actions[0][1][j], "ra") && ft_strcmp(&actions[1][1][j], "rb"))
// 			rr(head_a, head_b);
// 		else if (ft_strcmp(&actions[0][1][j], "rra") && ft_strcmp(&actions[1][1][j], "rrb"))
// 			rrr(head_a, head_b);
// 		else
// 		{
// 			if (ft_strcmp(&actions[0][1][j], "sa"))
// 				sa(head_a);
// 			else if (ft_strcmp(&actions[0][1][j], "ra"))
// 				ra(head_a);
// 			else if (ft_strcmp(&actions[0][1][j], "pb"))
// 				pb(head_a, head_b);
// 			if (ft_strcmp(&actions[1][1][j], "sb"))
// 				sb(head_b);
// 			else if (ft_strcmp(&actions[1][1][j], "rb"))
// 				rb(head_b);
// 			else if (ft_strcmp(&actions[1][1][j], "pa"))
// 				pa(head_a, head_b);
// 		}
// 		j++;
// 	}
// }

// /* normalize the numbers in the list between 0 and size
//    if flag == 0, normalize, otherwise denormalize */
// void	normalize(t_list **head, int flag)
// {
// 	static int	max;
// 	static int	min;
// 	static int	size;
// 	int			tmp;
// 	t_list		*current;

// 	current = *head;
// 	if(!max || !min || !size)
// 	{
// 		max = get_max(head);
// 		min = get_min(head);
// 		size = list_size(head);
// 	}
// 	while (current)
// 	{
// 		if (flag == 0)
// 		{
// 			tmp = current->data % size;
// 			// current->data = (((current->data - min) * size) / (max - min));
// 			current->data = ((current->data - min) * size) / (max - min);
// 		}
// 		else
// 			current->data = (current->data * (max - min)) / (100 + min);
// 		current = current->next;
// 	}
// }

// void sort(t_list **head_a, t_list **head_b)
// {
//     if(*head_a == NULL || (*head_a)->next == NULL)
//         return;
//     t_list *pivot = *head_a;
//     t_list *current = (*head_a)->next;
//     t_list *left = NULL;
//     t_list *right = NULL;

//     while(current != NULL)
//     {
//         if(current->data < pivot->data)
//         {
//             if(left == NULL)
//             {
//                 left = current;
//                 left->previous = NULL;
//                 left->next = NULL;
//             }
//             else
//             {
//                 left->next = current;
//                 current->previous = left;
//                 left = left->next;
//                 left->next = NULL;
//             }
//         }
//         else
//         {
//             if(right == NULL)
//             {
//                 right = current;
//                 right->previous = NULL;
//                 right->next = NULL;
//             }
//             else
//             {
//                 right->next = current;
//                 current->previous = right;
//                 right = right->next;
//                 right->next = NULL;
//             }
//         }
//         current = current->next;
//     }
//     if(left != NULL)
//     {
//         sort(&left, head_b);
//         left->previous = get_last(&left);
//         left->previous->next = left;
//     }
//     if(right != NULL)
//     {
//         sort(&right, head_b);
//         right->previous = get_last(&right);
//         right->previous->next = right;
//     }
//     *head_a = pivot;
//     pivot->previous = get_last(&left);
//     if(pivot->previous != NULL)
//         pivot->previous->next = pivot;
//     pivot->next = right;
//     if(pivot->next != NULL)
//         pivot->next->previous = pivot;
// }
