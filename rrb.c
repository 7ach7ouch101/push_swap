/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:00:12 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/22 00:20:32 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **b, int s)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lstsize(*b) <= 1)
	{
		return ;
	}
	tmp = *b;
	while ((*b)->next->next)
		*b = (*b)->next;
	tmp2 = (*b)->next;
	(*b)->next->next = tmp;
	(*b)->next = NULL;
	*b = tmp2;
	if(s == 1)
		write(1, "rrb\n", 4);
}
