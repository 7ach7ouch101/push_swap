/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:46:19 by mmeziani          #+#    #+#             */
/*   Updated: 2022/04/12 21:49:43 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void    sa(struct Node *head)
{
    int data;

    if(head->next == NULL)
        return ;
    data = head->data;
    head->data = head->next->data;
    head->next->data = data;
}