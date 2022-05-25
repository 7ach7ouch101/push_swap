/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:12:38 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/23 20:06:58 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a , int s)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lstsize(*a) <= 1)
		return ;
	tmp = *a;
	tmp2 = tmp->next;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
	*a = tmp2;
	if(s == 1)
		write(1, "ra\n", 3);
}
