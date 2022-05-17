/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:00:12 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/16 22:02:51 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(struct Node **b)
{
	struct Node	*tmp;
	struct Node	*tmp2;

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
	write(1, "rrb\n", 4);
}
