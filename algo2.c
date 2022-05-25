/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:32:57 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/22 00:20:32 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	big_instack(t_list *b)
{
	int	tmp;

	tmp = (b)->data;
	while (b)
	{
		if (tmp < (b)->data)
			tmp = (b)->data;
		b = (b)->next;
	}
	return (tmp);
}

int	check_for_location(int size, t_list *b)
{
	size = size / 2;
	while (size && b)
	{
		if (b->data == big_instack(b))
			return (1);
		b = (b)->next;
		size--;
	}
	return (0);
}

void	push_to_b(t_list **a, t_list **b)
{
	if (check_for_location(lstsize(*b), *b) == 1)
	{
		if ((*b)->data == big_instack(*b))
			pa(&*(a), &*(b), 1);
		else if ((*b)->next->data == big_instack(*b))
		{
			sb(*(b), 1);
			pa(&*(a), &*(b), 1);
		}
		else
			rb(&*(b), 1);
	}
	else if ((*b)->next == NULL)
		pa(&*(a), &*(b), 1);
	else
		rrb(&*(b), 1);
}
