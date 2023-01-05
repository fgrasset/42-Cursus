/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:14 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/05 13:35:04 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting algorithm */
void	sort(t_list *head_a, t_list *head_b, int count)
{
	int	max;
	int	min;

	max = max_min
	while (head_a != min && head_a->previous != max)
	{
		if (head_a->data > head_a->next->data && head_a->data != max)
			swap();
		rotate();
	}
}

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
		if (!isdigit(ft_itoa(str[i])))
			return 0;
		add_int(head, ft_itoa(str[i]));
		i++;
	}
	return 1;
}

/* launches the program */
int	main(int ac, char **av)
{
	int			i;
	int			j;
	static int	count;
	t_list		*head_a;
	t_list		*head_b;

	if (ac < 2)
		return (ft_putstr_fd("Error, send the stack of numbers\n", 2));
	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!isdigit(ft_itoa(av[i][j])))
				return (ft_putstr_fd("Error, one of the input is not a number\n", 2));
			add_int(head_a, ft_itoa(av[i][j]));
			count++;
		}
	}
}
