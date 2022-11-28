/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:14:17 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/28 10:44:30 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct t_Node{
	char			*buffer;
	struct t_Node	*next;
}	t_Node;

char	*get_next_line(int fd);
void	stash_fill(t_Node **head, char *stash);
void	stash_get(char *stash, char *line);
void	ft_bzero(void *s, int n);
void	stash_make(t_Node **head);

int		list_add(t_Node **head, int fd);
int		list_len(t_Node **head);
void	list_get(t_Node **head, char *line);
void	list_free(t_Node **head);
int		enter(char *string);

#endif