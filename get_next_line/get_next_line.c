/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/18 13:53:03 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	stash_add(t_Node *root, char *stash)
{
	int	i;
	int	j;
	struct t_Node	*tmp;

	tmp = root;
	i = -1;
	j = -1;
	while(tmp->next != NULL)
		tmp = tmp->next;
	while(tmp->chain[++i])
		if (tmp->chain[i] == '\n')
			while (tmp->chain[i])
			{
				stash[++j] = tmp->chain[i];
				i++;
			}
}

char	*get_next_line(int fd)
{
	int				check;
	struct t_Node	*root;
	char			*res;
	static char		stash[BUFFER_SIZE];

	if (fd <= 0 || BUFFER_SIZE == 0)
		return (NULL);
	root = malloc(sizeof(struct t_Node));
	check = list_add(root, fd);
	while (check == BUFFER_SIZE)
		check = list_add(root, fd);
	stash_add(root, stash);
	printf("stash: %s\n", stash);
	// if (0 < check < BUFFER_SIZE)
	// 	{

	// 	}
	
	// while (read(fd, buffer, BUFFER_SIZE) > 0)
	// {
	// 	if (ft_enter(buffer))
	// 		stash_add(buffer, stash);
	// 	list_add(root, fd);
	// }
	res = list_get(root);
	list_free(root);
	return (res);
}

int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}