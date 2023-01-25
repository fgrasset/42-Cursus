/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/25 11:15:40 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_list {
	int				data;
	int				index;
	struct t_list	*next;
	struct t_list	*previous;
}	t_list;

// typedef struct t_l
// {
// 	float	max;
// 	float	min;
// 	int		max_pos;
// 	int		min_pos;
// 	int		len;
// 	int		count;
// }	t_l;

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

//push_swap

//linked_list
void	add_int(t_list **head, int nb);
t_list	*get_first(t_list *head);
t_list	*get_last(t_list *head);
void	list_free(t_list *head);
int		check_head(t_list *head);

//math
int		max_min(t_list *head, int flag, int len);
int		get_max(t_list **head);
int		get_min(t_list **head);
void	normalize(t_list **head, int flag);

//push_swap_utils
int 	ft_strcmp(char *str1, char *str2);
int		list_size(t_list **head);
int		position(t_list *head, int number);
int 	ismaxmin(int nb);
int		isanumber(char *str);
void	print_list(t_list **head);
void	print_list_index(t_list **head);

//rotate
void	ra(t_list **head_a);
void	rb(t_list **head_b);
void	rr(t_list **head_a, t_list **head_b);

//reverse rotate
void	rra(t_list **head_a);
void	rrb(t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);

//swap & push
void	sa(t_list **head_a);
void	sb(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);
void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_b, t_list **head_a);

//sort
void	sort(t_list **head_a, t_list **head_b);
int		index_calcuation(t_list **head, int nb);
int		to_push(int nb, int i);
int		isordered(t_list **head);


#endif
