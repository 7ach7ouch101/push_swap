/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:16:06 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/28 21:36:31 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	small_instack(t_list *a)
{
	int	tmp;

	tmp = (a)->data;
	while (a)
	{
		if (tmp > (a)->data)
			tmp = (a)->data;
		a = (a)->next;
	}
	return (tmp);
}

int	get_min(t_list *a, int data)
{
	int	i;

	i = 0;
	while (a->data != data)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	sort_five(t_list **a, t_list **b)
{
	int	index;
	int	i;

	while (!is_sorted(*a))
	{
		i = 0;
		index = get_min(*a, small_instack(*a));
		if (index == -1)
			return ;
		if (index <= (lstsize(*a) / 2))
			while (i++ < index)
				ra(a, 1);
		else
			while (i++ < (lstsize(*a) - index))
				rra(a, 1);
		if (!is_sorted(*a))
			pb(*(&a), *(&b), 1);
	}
	while (*b)
		pa(*(&a), *(&b), 1);
}

void	sort_three(t_list **a)
{
	while (lstsize(*a))
	{
		if ((*a)->data > (*a)->next->next->data)
			ra(&*(a), 1);
		else if ((*a)->data > (*a)->next->data)
			sa(*(a), 1);
		else if ((*a)->next->data > (*a)->next->next->data)
			rra(&*(a), 1);
		else
			break ;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	if (parse(ac, av, &a) == 0 || is_sorted(a))
		return (0);
	if (lstsize(a) == 2)
		sort_two(&a);
	else if (lstsize(a) == 3)
		sort_three(&a);
	else if (lstsize(a) <= 5)
		sort_five (&a, &b);
	else
		above_five (&a, &b);
	freelist(&a, &b);
	return (0);
}
