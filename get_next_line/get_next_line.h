/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:14:17 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/18 13:38:58 by fgrasset         ###   ########.fr       */
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

typedef struct t_Node{
	char			*chain;
	struct t_Node 	*next;
} t_Node;

int		ft_enter(char buffer[BUFFER_SIZE]);
int		list_add(t_Node *root, int fd);
char	*list_get(t_Node *root);
void	list_free(t_Node *root);

char	*get_next_line(int fd);
void	stash_add(t_Node *root, char *stash);

#endif