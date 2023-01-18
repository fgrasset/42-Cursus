/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:14 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/18 14:56:23 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /* adds the string of numbers to the stack
//    returns false if error, true otherwise */
// int	add_to_stack(t_list *head, char *str)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (!isanumber(str))
// 			return 0;
// 		add_int(head, ft_atoi(str));
// 		i++;
// 	}
// 	return 1;
// }

/* returns true if nb is a double, false otherwise */
int	isdouble(t_list *head, int nb)
{
	t_list	*current;


	// ft_printf("%s\n", nb);
	if (!head)
		return (1);
	current = head;
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
int	array_to_add(char **nb, t_list *head)
{
	int	i;
	int	j;

	i = 0;
	while (nb[++i])
	{
		j = -1;
		if (!isanumber(nb[i]))
			return (0);
		while (nb[i][++j])
		{
			if (!isdouble(head, ft_atoi(nb[i])))
				return (0);
			add_int(head, ft_atoi(nb[i]));
		}
	}
	return (1);
}

/* moves half of stack A to stack B */
void	half_to_b(t_list *head_a, t_list *head_b)
{
	int	halfa;
	int	i;

	halfa = list_size(head_a) / 2;
	i = 0;
	while (i < halfa)
	{
		pb(head_b, head_a);
		i++;
	}
}

/* launches the program */
int	main(int ac, char **av)
{
	static t_list	*head_a;
	static t_list	*head_b;

	head_a = NULL,
	head_b = NULL;
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2));
	else if (ac == 2)
	{
		if (!array_to_add(ft_split(av[1], ' '), head_a))
			return (ft_putstr_fd("Error\n", 2));
	}
	else
	{
		if (!array_to_add(av, head_a))
			return (ft_putstr_fd("Error\n", 2));
	}
	half_to_b(head_a, head_b);
	print_list(head_a);
	write(1, "\n", 1);
	print_list(head_b);
	write(1, "test", 4);
	sort(head_a, head_b);
	return (0);
}
