/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:26:02 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/17 00:24:25 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int	*str, int i)
{
	int	j;
	int	n;
	int	tmp;

	j = 0;
	while (j < i)
	{
		n = j + 1;
		while (n < i)
		{
			if (str[j] > str[n])
			{
				tmp = str[j];
				str[j] = str[n];
				str[n] = tmp;
			}
			n++;
		}
		j++;
	}
}

void	fa(struct Node *a, int *str)
{
	int	i;

	i = 0;
	while (a)
	{
		str[i] = a->data;
		a = a->next;
		i++;
	}
	sort_arr(str, i);
}

void	above_five(struct Node **a, struct Node **b)
{
	int	var1;
	int	var2;
	int	*st;
	int	s;
	int	f;

	while (lstsize(*a) != 0)
	{
		f = ((s = 1, st = malloc(lstsize(*a) * sizeof(int)), fa(*a, st)), 0);
		var1 = ((var2 = st[(lstsize(*a) / 3) / 2]), st[lstsize(*a) / 3]);
		while ((*a && (s || f != (*a)->data)))
		{
			if ((*a)->data <= var1)
			{
				if ((*a)->data <= var2)
					((rb(&*(b))), pb(&*(a), &*(b)));
				else
					pb(&*(a), &*(b));
			}
			else 
				{if (s)
					f = ((s = 0), (*a)->data);
			ra(&*(a));
				}
		}
		free(st);
	}
	while ((*b))
		push_to_b(&*(a), &*(b));
}
