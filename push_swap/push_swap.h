/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/05 13:24:39 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_list
{
	int				*data;
	int				flag;
	struct t_list	*next;
	struct t_list	*previous;
}	t_list;

typedef struct t_l
{
	float	max;
	float	min;
	int		max_pos;
	int		min_pos;
	int		len;
	int		count;
}	t_l;

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

//linked_list
void	add_int(t_list *head, int nb);
t_list	*get_first(t_list *head);
t_list	*get_last(t_list *head);
void	list_free(t_list *head);
int		check_head(t_list *head);

//math
void	normalize(t_list *head, int flag);
int		max_min(t_list *head, int flag, int len);
int		get_max(t_list *head);
int		get_min(t_list *head);

//push_swap_utils
int		list_size(t_list *head);
int		position(t_list *head, int number);



#endif
