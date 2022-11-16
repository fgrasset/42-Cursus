/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:14:17 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/16 16:10:25 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct List{
	char	chain[BUFFER_SIZE];
	struct List *next;
} List;

int		ft_enter(char buffer[BUFFER_SIZE]);
void	list_add(List *root, char buffer[BUFFER_SIZE]);
char	*list_get(List *root);
void	list_free(List *root);

char	*get_next_line(int fd);
void	stash_add(char buffer[BUFFER_SIZE], char *stash);

#endif