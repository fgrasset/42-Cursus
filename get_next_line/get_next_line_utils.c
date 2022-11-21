/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:09:02 by fabien            #+#    #+#             */
/*   Updated: 2022/11/21 13:36:48 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*iterate in the buffer until it finds \n then returns the value it has to substract to the BUFFER_SIZE to get to the \n position*/
int	ft_enter(char buffer[BUFFER_SIZE + 1])
{
	int	i;

	i = -1;
	if (buffer[0] == '\n')
		return (BUFFER_SIZE);
	while (buffer[++i])
		if (buffer[i] == '\n')
			return (BUFFER_SIZE - (i + 1));
	return (0);
}

/*creates a new node and uses read to fill it*/
int	list_add(t_Node *root, int fd)
{
	struct t_Node	*tmp;
	int				i;

	tmp = root;
	i = 0;
	while(tmp && tmp->next)
		tmp = tmp->next;
	tmp = malloc(sizeof(struct t_Node));
	if (!tmp)
		return (0);
	// tmp->chain = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (!tmp->chain)
	// 	return (0);
	i = read(fd, tmp->chain, BUFFER_SIZE);
	tmp->chain[i] = '\0';
	// while ((i < BUFFER_SIZE) && tmp->next->chain[i - 1] != '\n')
	// {
	// 	buffer[i] = tmp->next->chain[i];
	// 	i++;
	// }
	tmp->next = NULL;
	return (i - ft_enter(tmp->chain));
}

/*takes all of the nodes to malloc the line, and copies all the nodes content in the line*/
char	*list_get(t_Node *root, int check)
{
	struct t_Node	*tmp;
	char			*line;
	int				i;
	int				j;

	i = 0;
	j = -1;
	tmp = root;
	while (tmp && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	line = malloc(sizeof(char) * (((i - 1) * BUFFER_SIZE) + (BUFFER_SIZE - (check - 1))));
	if (!line)
		return (NULL);
	tmp = root;
	while (tmp && tmp->next)
	{
		i = -1;
		while (tmp->chain[++i] && tmp->chain[i] != '\n')
			line[++j] = tmp->chain[i];
		tmp = tmp->next;
	}
	line[++j] = '\0';
	return (line);
}

/*frees all the malloc that are still being used*/
void	list_free(t_Node *root)
{
	struct t_Node	*tmp;

	while (root && root->next)
	{
		tmp = root;
		root = root->next;
		free(tmp);
	}
}