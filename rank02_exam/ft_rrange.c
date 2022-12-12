/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:15:19 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 13:24:22 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	size;
	int	*range;

	size =  end - start;
	if (size < 0)
		size *= -1;
	range = malloc(sizeof(int) * size);
	while (*range)
	{
		*range = end;
		end--;
		range++;
	}
	return (range);
}

int	main()
{
	printf("%i\n", ft_rrange(1, 3));
}