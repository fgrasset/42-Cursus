
# include "get_next_line.h"

/* links actual element, and returns the next one */
t_gnl	next_buf(t_gnl *gnl, int fd)
{
	t_gnl	*buf_next;
	int		check;

	buf_next = malloc(sizeof(t_gnl));
	buf_next->buf = malloc(sizeof(char) * BUFFER_SIZE);
	buf_next->stop = 0;
	check = read(fd, buf_next->buf, BUFFER_SIZE);
	if (check == 0)
		buf_next->stop = 1;
	else if (check < 0)
		buf_next->stop = -1;
}

/* returns the length of the line to malloc */
int	line_len(t_gnl *head)
{
	t_gnl	*current;
	int		len;
	int		i;

	current = head;
	len == 0;
	while(current->next)
	{
		i = -1;
		while (++i < BUFFER_SIZE && current->buf[i] != '\n')
			len++;
		current = current->next;
	}
	return (len)
}
