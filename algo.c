/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:26:02 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/24 20:20:47 by mmeziani         ###   ########.fr       */
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

void	fa(t_list *a, int *str)
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
void	push_to_a(t_list **a, t_list **b, t_vars v)
{
	while ((*a && (v.start || v.first != (*a)->data)))
	{
		if ((*a)->data <= v.var1)
		{
			if ((*a)->data <= v.var2)
			{
				pb(&*(a), &*(b), 1);
				rb(&*(b), 1);
			}
			else
			{
				pb(&*(a), &*(b), 1);
			}
		}
		else
		{
			if(v.start)
			{
				v.first = (*a)->data;
				v.start = 0;
			}
			ra(&*(a), 1);
		}
	}
}
void	above_five(t_list **a, t_list **b)
{
	t_vars v;

	while (lstsize(*a) != 0)
	{
		v.first = 0;
		v.start = 1;
		v.ar = malloc(lstsize(*a) * sizeof(int));
		if (!v.ar)
			return ;
		fa(*a, v.ar);
		v.var1 = v.ar[lstsize(*a) / 3];
		v.var2 = v.ar[(lstsize(*a) / 3) / 2];
		push_to_a(a,b,v);
		free(v.ar);
	}
	while ((*b))
		push_to_b(&*(a), &*(b));
}