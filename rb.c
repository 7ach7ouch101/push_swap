/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:54:47 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/22 00:20:32 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

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
