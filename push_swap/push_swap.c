/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:14 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/26 16:39:07 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns true if nb is a double, false otherwise */
int	isdouble(t_list **head, int nb)
{
	t_list	*current;

	if (!head)
		return (1);
	current = *head;
	while (current)
	{
		if (current->data == nb)
			return (1);
		current = current->next;
	}
	return (0);
}

/* adds an array to the stack A
	returns false if error, true otherwise */
int	array_to_add(char **nb, t_list **head)
{
	int	i;

	i = 0;
	while (nb[++i])
	{
		if (!isanumber(nb[i]))
			return (0);
		if (isdouble(head, ft_atoi(nb[i])))
			return (0);
		add_int(head, ft_atoi(nb[i]));
	}
	return (1);
}

/* launches the program */
int	main(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;
	// t_list	*current;

	head_a = NULL,
	head_b = NULL;
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2));
	else if (ac == 2)
	{
		if (!array_to_add(ft_split(av[1], ' '), &head_a))
			return (ft_putstr_fd("Error\n", 2));
	}
	else
	{
		if (!array_to_add(av, &head_a))
			return (ft_putstr_fd("Error\n", 2));
	}
	// head_a->previous = get_last(&head_a);
	write(1, "stack A:", 8);
	print_list(head_a);
	write(1, "index A:", 8);

	// print_list_index(head_a);
	// ra(&head_a);
	// pb(&head_b, &head_a);
	// printf("head.a: %d\nhead_a.next: %d\nhead_a.next.next: %d\n", head_a->data, head_a->next->data, head_a->next->next->data);
	// current = head_a;
	// pa(&head_a, &head_b);
	// printf("head.a: %d\nhead_a.next: %d\nhead_a.next.next: %d\n", head_a->data, head_a->next->data, head_a->next->next->data);

	sort(&head_a, &head_b);
	write(1, "stack A:", 8);

	// while (current)
	// {
	// 	printf("%d", current->data);
	// 	current = current->next;
	// }
	// write(1, "\n", 1);

	print_list(head_a);
	return (0);
}

/* moves half of stack A to stack B */
// void	half_to_b(t_list **head_a, t_list **head_b)
// {
// 	int	halfa;
// 	int	i;

// 	halfa = list_size(head_a) / 2;
// 	i = 0;
// 	while (i < halfa)
// 	{
// 		pb(head_b, head_a);
// 		i++;
// 	}
// 	(*head_a)->previous = get_last(head_a);
// 	(*head_b)->previous = get_last(head_b);
// }
