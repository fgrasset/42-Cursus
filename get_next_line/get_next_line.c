/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:10:40 by fgrasset          #+#    #+#             */
/*   Updated: 2022/11/14 20:13:04 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;

	buffer = read(fd, BUFFER_SIZE, 1);


}

char	*end_line(char *s)
{
	
}