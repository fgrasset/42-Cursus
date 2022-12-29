/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:04 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/29 17:33:26 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_list
{
	int				*data;
	struct t_list	*next;
	struct t_list	*previous;
}	t_list;

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

//linked_list
void	add_int(t_list *head, int nb);
t_list	*get_first(t_list *head);
t_list	*get_last(t_list *head);
void	list_free(t_list *head);
int		check_head(t_list *head);



#endif
