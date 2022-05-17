/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:54:47 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/16 21:56:05 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(struct Node **b)
{
	struct Node	*tmp;
	struct Node	*tmp2;

	if (lstsize(*b) <= 1)
		return ;
	tmp = *b;
	tmp2 = tmp->next;
	while ((*b)->next)
		*b = (*b)->next;
	(*b)->next = tmp;
	(*b)->next->next = NULL;
	*b = tmp2;
	write(1, "rb\n", 3);
}
