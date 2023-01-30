/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:55:37 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/30 10:37:36 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns true if it is a number, false otherwise */
int	isanumber(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isadigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* prints the element of the list */
void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d ", current->data);
		current = current->next;
	}
	write(1, "\n", 1);
}

/*prints the index */
void	print_list_index(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d ", current->index);
		current = current->next;
	}
	write(1, "\n", 1);
}

/* returns length of linked list */
int	list_size(t_list *head)
{
	t_list	*current;
	int		count;

	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/* free the split and returns the flag int
   if condition == "f", frees otherwise not */
int	free_split(char **tofree, int flag, char condition)
{
	int	i;

	if (condition == 'f')
	{
		i = -1;
		while (tofree[++i])
		{
			free(tofree[i]);
		}
		free(tofree);
	}
	return (flag);
}
