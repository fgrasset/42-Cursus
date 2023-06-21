#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	char			*buf;
	int				stop;
	struct s_gnl	*next;
} t_gnl;

t_gnl	next_buf(t_gnl *gnl, int fd);
int		line_len(t_gnl *head);


# endif
