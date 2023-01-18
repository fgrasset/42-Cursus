/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:55:37 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/18 14:34:00 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* returns false if strings are the same */
int ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* returns length of linked list */
int	list_size(t_list *head)
{
	t_list	*current;
	int		count;

	if (head == NULL)
		return (0);
	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/* returns the position of the number in
   the linked list */
int	position(t_list *head, int number)
{
	t_list *current;
	int		position;

	if (head == NULL)
		return (0);
	position = 0;
	current = head;
	while (current && current->data != number)
	{
		position++;
		current = current->next;
	}
	return (position);
}

/* checks if nb is in int scope false if not */
int	ismaxmin(int nb)
{
	if (nb > 2147483647)
		return 0;
	else if (nb < -2147483648)
		return 0;
	else
		return 1;
}

/* returns true if it is a number, false otherwise */
int	isanumber(char *str)
{
	int	i;

	i = 0;
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
	t_list *current;

	current = get_last(head);
	while (current)
	{
		ft_printf("%d\n", current->data);
		current = current->next;
	}
}
