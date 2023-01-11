/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:40:04 by fgrasset          #+#    #+#             */
/*   Updated: 2023/01/11 14:39:23 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_list
{
	int				data;
	int				flag;
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
int	add_to_stack(t_list *head, char *str);

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
int ft_strcmp(char *str1, char *str2);
int		list_size(t_list *head);
int		position(t_list *head, int number);

//r
void	ra(t_list *head_a);
void	rb(t_list *head_b);
void	rr(t_list *head_a, t_list *head_b);

//rr
void	rra(t_list *head_a);
void	rrb(t_list *head_b);
void	rrr(t_list *head_a, t_list *head_b);

//sp
void	sa(t_list *head_a);
void	sb(t_list *head_b);
void	ss(t_list *head_a, t_list *head_b);
void	pa(t_list *head_a, t_list *head_b);
void	pb(t_list *head_b, t_list *head_a);

//sort
void	sort(t_list *head_a, t_list *head_b);
char	***actions(char *str, char stack);
void	combine(char ***actions, t_list *head_a, t_list *head_b);

#endif
