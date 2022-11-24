/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/24 13:22:22 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	stash_add(t_Node *root, char *stash, int check)
// {
// 	int	i;
// 	int	j;
// 	struct t_Node	*tmp;

// 	tmp = root;
// 	i = -1;
// 	// j = -1;
// 	while(tmp->next != NULL)
// 	{
// 		printf("test");
// 		tmp = tmp->next;
// 		printf("tmp.next: %s\n", tmp->chain);
// 	}
	
// 	printf("chain: %s\n", tmp->chain);
// 	while(check <= BUFFER_SIZE)
// 	{
// 		// if (tmp->chain[i] == '\n')
// 		// while (tmp->chain[++i])
// 		// {
// 		stash[++i] = tmp->chain[check++];
// 		printf("chain[i] : %c\n", tmp->chain[i]);
// 		// }
// 	}
// 	stash[++j] = '\0';
// }

// char	*get_next_line(int fd)
// {
// 	int				check;
// 	struct t_Node	*root;
// 	char			*res;
// 	static char		stash[BUFFER_SIZE + 1];

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, stash, 0) < 0)
// 		return (NULL);
// 	root = malloc(sizeof(struct t_Node));
// 	// check = list_add(root, fd);			//check either 10 if no \n, or the position of the \n
// 	// printf("check: %d\n", check);
// 	while (check == BUFFER_SIZE)
// 	{
// 		check = list_add(root, fd);
// 		printf("thecheck: %d\n", check);
// 	}
// 	// write(1, "test", 4);
// 	stash_add(root, stash, check);
// 	printf("stash: %s\n", stash);
	
// 	// while (read(fd, buffer, BUFFER_SIZE) > 0)
// 	// {
// 	// 	if (ft_enter(buffer))
// 	// 		stash_add(buffer, stash);
// 	// 	list_add(root, fd);
// 	// }
// 	res = list_get(root, check);
// 	list_free(root);
// 	return (res);
// }

char	*get_next_line(int fd)
{
	static char	*stash;
	t_Node		*head;
	char		*res;

	head = NULL;
	if (!stash)
	{	
		stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		stash[0] = 0;
	}
	while (list_add(&head, fd) == 0);
	stash_fill(&head, stash);
	res = malloc(sizeof(char) * (list_len(&head) + 1));
	if (!res)
		return (NULL);
	ft_bzero(res, list_len(&head) + 1);
	stash_get(stash, res);
	list_get(&head, res);
	list_free(&head);
	write(1,"test",4);
	return (res);
}


/*fills the stash with the elements after the \n in the last buffer of the linked list*/
void	stash_fill(t_Node **head, char *stash)
{
	t_Node	*current;
	int		count;
	int		i;

	if (*head == NULL)
		return;
	current = *head;
	count = 0;
	while (current->next != NULL)
		current = current->next;
	i = -1;
	while (current->buffer[++i] && current->buffer[i] != '\n')
		count++;
	i = -1;
	while (current->buffer[++count])
		stash[++i] = current->buffer[count];
	stash[++i] = '\0';
}


/*fills res with the stash from \n to the end*/
void	stash_get(char *stash, char *res)
{
	int	i;
	int	j;

	i = enter(stash);
	j = 0;
	if (!stash)
		return;
	while (stash[i + j])
	{
		res[j] = stash[i + j];
		j++; 
	}
	res[j] = '\0';
}

/*basically bzero but made by hand*/
void	ft_bzero(void *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	printf("result: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}