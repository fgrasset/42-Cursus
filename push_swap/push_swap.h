/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/30 10:38:09 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

typedef struct t_list {
	int				data;
	int				index;
	struct t_list	*next;
}	t_list;

//linked_list
void	add_int(t_list **head, int nb);
t_list	*get_last(t_list *head);
void	list_free(t_list **head);

//push_swap_utils
int		list_size(t_list *head);
int		isanumber(char *str);
void	print_list(t_list *head);
void	print_list_index(t_list *head);
int		free_split(char **tofree, int flag, char condition);

//rotate
void	ra(t_list **head_a);

//reverse rotate
void	rra(t_list **head_a);

//swap & push
void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_b, t_list **head_a);
void	sa(t_list **head_a);

//sort
void	sort(t_list **head_a, t_list **head_b);
int		index_calcuation(t_list **head, int nb);
int		to_push(int nb, int i);
int		isordered(t_list *head);

//sort small
void	sort_3(t_list **head);
void	sort_4(t_list **head_a, t_list **head_b);
void	sort_5(t_list **head_a, t_list **head_b);

#endif
