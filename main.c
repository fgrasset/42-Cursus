/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:09:38 by fabien            #+#    #+#             */
/*   Updated: 2022/10/26 16:26:53 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int main(int ac, char **av)
{
    (void) ac;
    (void) av;

    printf("Test de isalnum --- Expected result (1)\n");
    printf("result of ft_isalnum: %d\n", ft_isalnum(20));
    printf("result of isalnum: %d\n", isalnum(20));

    printf("Test de isalpha --- Expected result (1)\n");
    printf("result of ft_isalpha: %d\n", ft_isalpha('a'));
    printf("result of isalpha: %d\n", isalpha('a'));

    printf("Test de isdigit --- Expected result (1)\n");
    printf("result of ft_isdigit: %d\n", ft_isdigit(8));
    printf("result of isdigit : %d\n", isdigit(8));

    printf("Test de strlen --- Expected result (15)\n");
    printf("result of ft_strlen: %zu\n", ft_strlen("Salut cest cool"));
    printf("result of strlen: %lu\n", strlen("Salut cest cool"));

    printf("Test de toupper --- Expected result (A)\n");
    printf("result of ft_toupper: %c\n", ft_toupper('a'));
    printf("result of toupper: %c\n", toupper('a'));

    printf("Test de tolower --- Expected result (z)\n");
    printf("result of ft_tolower: %c\n", ft_tolower('Z'));
    printf("result of tolower: %c\n", tolower('Z'));

    printf("Test de memset --- Expected result (cccccccc)\n");
    char b[100];
    char b_test[100];
    ft_memset(b, 'c', 8);
    memset(b_test, 'c', 8);
    printf("result of ft_memset: %s\n", b);
    printf("result of memset: %s\n", b_test);

    printf("Test de isascii --- Expected result (-)\n");
    printf("result of ft_isascii: %c\n", ft_isascii(45));
    printf("result of isascii: %c\n", isascii(45));

}