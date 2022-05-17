/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:34:56 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/14 02:38:38 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(struct Node **a, struct Node **b)
{
	struct Node	*tmp;

	if ((*b) == NULL)
	{
		return ;
	}
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write (1, "pa\n", 3);
}
