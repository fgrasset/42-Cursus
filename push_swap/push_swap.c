/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:14 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/29 17:36:19 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting algorithm */
void	sort(t_list *head_a, t_list *head_b, int count)
{

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
