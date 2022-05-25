/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:59:40 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/22 22:49:02 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list **b, int s)
{
	t_list	*tmp;
	if ((*a) == NULL)
	{
		return ;
	}
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	if(s == 1)
		write(1, "pb\n", 3);
}
