/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:27:00 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/22 00:20:32 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*tmp2;
	t_list	*tmp;

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
