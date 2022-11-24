/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:14:17 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/24 13:17:02 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

// typedef struct t_Node{
// 	char			chain[BUFFER_SIZE + 1];
// 	struct t_Node 	*next;
// } t_Node;

// int		ft_enter(char buffer[BUFFER_SIZE + 1]);
// int		list_add(t_Node *root, int fd);
// char	*list_get(t_Node *root, int check);
// void	list_free(t_Node *root);

// char	*get_next_line(int fd);
// void	stash_add(t_Node *root, char *stash, int check);

typedef struct t_Node{
	char			*buffer;
	struct t_Node 	*next;
} t_Node;


char	*get_next_line(int fd);
void	stash_fill(t_Node **head, char *stash);
void	stash_get(char *stash, char *res);
void	ft_bzero(void *s, int n);

int		list_add(t_Node **head, int fd);
int		list_len(t_Node **head);
void	list_get(t_Node **head, char *res);
void	list_free(t_Node **head);
int		enter(char *string);


#endif