/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/17 15:59:01 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	stash_add(char buffer[BUFFER_SIZE], char *stash)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while(++i <= BUFFER_SIZE)
		if (buffer[i] == '\n')
			while (++i <= BUFFER_SIZE)
				stash[++j] = buffer[i];
}

char	*get_next_line(int fd)
{
	struct t_Node	*root;
	char			*res;
	char			buffer[BUFFER_SIZE];
	static char		stash[BUFFER_SIZE];

	if (fd == 0)
		return (NULL);
	root = malloc(sizeof(struct t_Node));
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (ft_enter(buffer))
			stash_add(buffer, stash);
		list_add(root, buffer, fd);
	}
	res = list_get(root);
	list_free(root);
	return (res);
}