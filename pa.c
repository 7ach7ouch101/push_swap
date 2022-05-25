/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:34:56 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/22 00:20:32 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, int s)
{
	t_list	*tmp;

	if ((*b) == NULL)
	{
		return ;
	}
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if(s == 1)
		write (1, "pa\n", 3);
}
