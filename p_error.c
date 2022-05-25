/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:37:27 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/23 23:58:27 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    p_error(void)
{
    write(2, "Error\n", 6);
	    exit (1);
}

void    check(char *s)
{
    int i;
    int b;
    
    i = 0;
    b = 0;
    while (s[i])
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            b++;
            break;
        }
        i++;
    }
    if (!b)
        p_error();
}