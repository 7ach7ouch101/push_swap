/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:27:00 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/16 21:58:24 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(struct Node **a)
{
	struct Node	*tmp2;
	struct Node	*tmp;

	if (lstsize(*a) <= 1)
	{
		return ;
	}
	tmp = *a;
	while ((*a)->next->next)
		*a = (*a)->next;
	tmp2 = (*a)->next;
	(*a)->next->next = tmp;
	(*a)->next = NULL;
	*a = tmp2;
	write(1, "rra\n", 4);
}
