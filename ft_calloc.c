/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:31:31 by fabien            #+#    #+#             */
/*   Updated: 2022/10/30 17:54:06 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*ptr;

	ptr = malloc(count * size);
	if (ptr == (NULL))
		return ((NULL));
	return (ptr);
}
