/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:42:11 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/10 11:03:57 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* malloc ptr and returns false if there is an error in the malloc */
int	my_malloc(void	**ptr, int size)
{
	*ptr = malloc(size);

	if (*ptr == NULL) {
		return (0);
	}
	return (1);
}
