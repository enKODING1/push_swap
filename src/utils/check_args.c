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

int is_space(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}

int is_valid_str(char *s)
{
    int i;
    int num_flag;

    i = 0;
    num_flag = 0;
    while (s[i])
    {
        if ((s[i] == '-' || s[i] == '+') && (ft_isdigit(s[i + 1])))
        {
            i++;
            continue;
        }
        if (!ft_isdigit(s[i]) && !is_space(s[i]))
            return 0;
        i++;
    }
    return 1;
}

int check_args(int argc, char **argv)
{
    char **temp_args;
    int i;
   
    i = 0;
    if (argc == 2)
        temp_args = ft_split(argv[1], ' ');
    else if (argc > 2)
    {
        i = 1;
        temp_args = argv;
    }

    while(temp_args[i])
    {
       if (!is_valid_str(temp_args[i++]))
       {
            ft_putstr_fd("Error\n", 1); 
            return 0;
       }
    }
    return 1;
}