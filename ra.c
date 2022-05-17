/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:12:38 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/17 03:24:52 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(struct Node **a)
{
	struct Node	*tmp;
	struct Node	*tmp2;

	if (lstsize(*a) <= 1)
		return ;
	tmp = *a;
	tmp2 = tmp->next;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
	*a = tmp2;
	write(1, "ra\n", 3);
}
