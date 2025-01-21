/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:42 by skang             #+#    #+#             */
/*   Updated: 2025/01/11 21:17:43 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int valid_args(int argc, char **argv)
{
    char **temp_args;
    int i;
   
    i = 0;
    if (argc == 2)
        temp_args = ft_split(argv[1], ' ');
    if (argc > 2)
    {
        i = 1;
        temp_args = argv;
    }

    // while ()

}

int two_pointer_to_string(char **data)
{

}