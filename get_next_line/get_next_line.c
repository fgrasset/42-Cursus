/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/21 13:52:11 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	stash_add(t_Node *root, char *stash, int check)
{
	int	i;
	int	j;
	struct t_Node	*tmp;

	tmp = root;
	i = -1;
	// j = -1;
	while(tmp && tmp->next)
	{
		tmp = tmp->next;
		printf("tmp.next: %s\n", tmp->chain);
	}
	
	while(check <= BUFFER_SIZE)
	{
		printf("chain[i] : %c\n", tmp->chain[i]);
		// if (tmp->chain[i] == '\n')
		// while (tmp->chain[++i])
		// {
		stash[++i] = tmp->chain[check++];
		printf("chain[i] : %c\n", tmp->chain[i]);
		// }
	}
	stash[++j] = '\0';
}

char	*get_next_line(int fd)
{
	int				check;
	struct t_Node	*root;
	char			*res;
	static char		stash[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, stash, 0) < 0)
		return (NULL);
	root = malloc(sizeof(struct t_Node));
	check = list_add(root, fd);			//check either 10 if no \n, or the position of the \n
	printf("check: %d\n", check);
	while (check == BUFFER_SIZE)
	{
		check = list_add(root, fd);
		printf("thecheck: %d\n", check);
	}
	// write(1, "test", 4);
	stash_add(root, stash, check);
	printf("stash: %s\n", stash);
	
	// while (read(fd, buffer, BUFFER_SIZE) > 0)
	// {
	// 	if (ft_enter(buffer))
	// 		stash_add(buffer, stash);
	// 	list_add(root, fd);
	// }
	res = list_get(root, check);
	list_free(root);
	return (res);
}

int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	printf("result: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}