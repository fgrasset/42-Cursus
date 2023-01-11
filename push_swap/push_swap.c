/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:14 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/11 15:22:21 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* adds the string of numbers to the stack
   returns false if error, true otherwise */
int	add_to_stack(t_list *head, char *str)
{
	t_list	*current;
	int		i;

	current = head;
	i = 0;
	while (str[i])
	{
		if (!isdigit(ft_atoi(&str[i])))
			return 0;
		add_int(head, ft_atoi(&str[i]));
		i++;
	}
	return 1;
}

/* returns true if nb is a double, false otherwise */
int	isdouble(t_list *head, int nb)
{
	t_list	*current;

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

	i = 1;
	while (nb[++i])
	{
		j = -1;
		while (nb[i][++j])
		{
			if (!isdigit(ft_atoi(&nb[i][j])) && !isdouble(head, ft_atoi(&nb[i][j])))
				return (0);
			add_int(head, ft_atoi(&nb[i][j]));
		}
	}
	return (1);
}

/* moves half of stack A to stack B */
void	half_to_B(t_list *head_a, t_list *head_b)
{
	int	halfA;
	int	i;

	halfA = list_size(head_a) / 2;
	i = 0;
	while (i < halfA)
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
	half_to_B(head_a, head_b);
	sort(head_a, head_b);
	return (0);
}
