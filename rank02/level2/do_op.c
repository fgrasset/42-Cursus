/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:11:50 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/08 17:21:04 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **ag)
{
	if (ac == 4)
	{
		int	a = atoi(ag[1]);
		int	b = atoi(ag[3]);

		if (ag[2][0] == '+')
			printf("%d", a + b);
		else if (ag[2][0] == '-')
			printf("%d", a - b);
		else if (ag[2][0] == '*')
			printf("%d", a * b);
		else if (ag[2][0] == '/')
			printf("%d", a / b);
		else if (ag[2][0] == '%')
			printf("%d", a % b);
	}
	// write(1, "\n", 1);
	printf("\n");
	return (0);
}
