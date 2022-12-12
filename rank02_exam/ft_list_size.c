/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:30:34 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 13:33:56 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list	*current;
	int		len;

	if (begin_list == 0)
		return (0);
	current = begin_list;
	len = 0;
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}