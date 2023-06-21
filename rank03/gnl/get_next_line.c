# include "get_next_line.h"

int		contains_n(char	*buf);
char	*make_line(t_gnl *gnl, t_gnl *head, int n);
int		stash_fill(t_gnl *gnl);




char	*get_next_line(int fd)
{
	t_gnl	*head;
	t_gnl	*gnl;
	char	*line;
	int		n;

	head = malloc(sizeof(t_gnl));
	if (read(fd, head->buf, BUFFER_SIZE) <= 0)
		;
	while (!gnl->stop && !contains_n(gnl->buf))
	{

	}
	if (gnl->stop == 1)
	{
		// make_line, free stash and the rest
		line = make_line(gnl, head, n);
	}
	else
	{
		// make_line, stash_fill
	}

}

/* returns true if \n is in the buffer and returns the place of \n*/
int	contains_n(char	*buf)
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return (i);
	}
	return (0);
}

/* malloc */
char	*make_line(t_gnl *gnl, t_gnl *head, int n)
{
	char	*line;
	int		i;
	int		j = -1;
	t_gnl	*current = head;

	line = malloc(sizeof(char) * line_len(head));
	while (current->next)
	{
		i = -1;
		if (current->stop = 1)
		{
			while (++i < n)
				line[++j] = current->buf[i];
		}
		else
		{
			while (++i < BUFFER_SIZE)
				line[++j] = current->buf[i];
		}
		current = current->next;
	}
	line[++j] = '\0';
	return (line);
}

int	stash_fill(t_gnl *gnl)
{

}
