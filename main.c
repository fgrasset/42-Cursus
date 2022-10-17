/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:09:38 by fabien            #+#    #+#             */
/*   Updated: 2022/10/17 16:52:13 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int main(int ac, char **av)
{
    (void) ac;

    printf("Test de memset --- Expected result ()");
    char str[20];
    memset(str, '*', 9);
    printf("result of memset: ", str);


    printf("Test de bzero --- Expected result ()");

}