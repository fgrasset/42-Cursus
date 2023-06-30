# include "get_next_line.h"

// int		ft_strlen(char *str);
// // int		has_n(char *str);
// char	*has_n(const char *s, int c);
// // char	*ft_strjoin(char *stash, char *buffer);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*fill_stash(int fd, char *stash);
// char	*extract_line(char *stash);
// char	*new_stash(char *stash);

// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE  < 1)
// 	{
// 		free(stash);
// 		stash = 0;
// 		return (NULL);
// 	}
// 	if (stash == NULL)
// 	{
// 		stash = malloc(sizeof(char) * 1);
// 		if (stash == NULL)
// 			return (NULL);
// 	}
// 	stash = fill_stash(fd, stash);
// 	if (*stash == 0)
// 	{
// 		free(stash);
// 		return (stash = 0);
// 	}
// 	line = extract_line(stash);
// 	stash = new_stash(stash);
// 	return (line);
// }

// char	*fill_stash(int fd, char *stash)
// {
// 	char	*buffer;
// 	int		bytes = 1;

// 	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	while (bytes != 0 && has_n(stash, '\n') == 0)
// 	{
// 		bytes = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[bytes] = '\0';

// 		stash = ft_strjoin(stash, buffer);
// 	}
// 	free(buffer);
// 	return (stash);
// }

// char	*extract_line(char *stash)
// {
// 	char	*line;
// 	int		i = 0;
// 	int		j = 0;

// 	if (stash == NULL)
// 		return (NULL);
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	if (stash[i] == '\n')
// 		i++;
// 	line = malloc(sizeof(char) * (i + 1));
// 	if (!line)
// 		return (NULL);
// 	while (j < i)
// 	{
// 		line[j] = stash[j];
// 		j++;
// 	}
// 	line[j] = '\0';
// 	return (line);
// }

// char	*new_stash(char *stash)
// {
// 	char	*new;
// 	int		i = 0;
// 	int		j = 0;

// 	if (stash == NULL)
// 		return (NULL);
// 	while (stash[i] && stash[i] != '\n')
// 		i++;
// 	if (stash[i] == '\n')
// 		i++;
// 	new = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
// 	if (!new)
// 		return (NULL);
// 	while (stash[i])
// 	{
// 		new[j] = stash[i];
// 		i++;
// 		++j;
// 	}
// 	free(stash);
// 	new[j] = '\0';
// 	return (new);
// }

// int	ft_strlen(char *str)
// {
// 	int	i = 0;

// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	has_n(char *str)
// {
// 	int	i = -1;

// 	if (str == NULL)
// 		return (0);
// 	while (str[++i])
// 	{
// 		if (str[i] == '\n')
// 			return (1);
// 	}
// 	return (0);
// }

// char	*ft_strjoin(char *stash, char *buffer)
// {
// 	char	*new;
// 	int		i;
// 	int		j;

// 	new = malloc(sizeof(char) * (ft_strlen(stash) + (ft_strlen(buffer) + 1)));
// 	if (!new)
// 		return (NULL);
// 	i = -1;
// 	j = -1;
// 	while (stash[++i])
// 		new[i] = stash[i];
// 	while (buffer[++j])
// 		new[i + j] = buffer[j];
// 	free(stash);
// 	j++;
// 	new[j + i] = '\0';
// 	return (new);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*ptr;
// 	int		i;
// 	int		j;

// 	i = -1;
// 	j = 0;
// 	ptr = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
// 	if (ptr == 0)
// 		return (NULL);
// 	while (s1[++i] != '\0')
// 		ptr[i] = s1[i];
// 	while (s2[j] != '\0')
// 	{
// 		ptr[i + j] = s2[j];
// 		j++;
// 	}
// 	ptr[i + j] = '\0';
// 	free((char *)s1);
// 	return (ptr);
// }

// char	*has_n(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char)c)
// 		{
// 			return ((char *)&s[i]);
// 		}
// 		i++;
// 	}
// 	if ('\0' == (char)c)
// 	{
// 		return ((char *)&s[i]);
// 	}
// 	return (0);
// }


// char	*get_next_line(int fd)
// {
// 	char	*buffer;
// 	char	character;
// 	int		i = 0;
// 	int		rd = 0;

// 	if (BUFFER_SIZE < 1)
// 		return (NULL);
// 	buffer = malloc(sizeof(char) * 100000);
// 	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
// 	{
// 		buffer[i] = character;
// 		if (character == '\n')
// 			break ;
// 		i++;
// 	}
// 	buffer[++i] = '\0';
// 	if (!rd || i == 0 || (!buffer[i - 1] && !rd))
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	return (buffer);
// }

// char	*get_next_line(int fd)
// {
// 	char	*buffer;
// 	char	character;
// 	int		i = 0;
// 	int		rd = 0;

// 	if (BUFFER_SIZE < 1)
// 		return (NULL);
// 	buffer = malloc(sizeof(char) * 100000);
// 	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
// 	{
// 		buffer[i] = character;
// 		if (character == '\n')
// 			break ;
// 		i++;
// 	}
// 	buffer[++i] = '\0';
// 	if (!rd || i == 0 || !buffer[i - 1] && !rd)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	return (buffer);
// }

char	*get_next_line(int fd)
{
	char	*buffer;
	char	character;
	int		i = 0;
	int		rd = 0;

	if (BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char) * 100000);
	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)))
	{
		buffer[i] = character;
		if (character == '\n')
			break ;
		i++;
	}
	buffer[++i] = '\0';
	if (!rd || i == 0 || !buffer[i - 1] && !rd)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

int	main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
