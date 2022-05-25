/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:16:06 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/25 01:39:48 by mmeziani         ###   ########.fr       */
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

void	sort_five(t_list **a, t_list **b)
{
	while (*a)
	{
		if (lstsize(*b) == 2)
			break ;
		if ((*a)->data == small_instack(*a))
			pb(&*(a), &*(b), 1);
		else
			ra(&*(a), 1);
	}
	while (lstsize(*a) == 3)
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
	while (*b)
		pa(&*(a), &*(b), 1);
}

void	sort_three(t_list **a)
{
	if ((*a)->data > (*a)->next->data)
	{
		if ((*a)->next->data > (*a)->next->next->data)
		{
			sa(*a, 1);
			rra(&*(a), 1);
		}
		else if ((*a)->data > (*a)->next->next->data)
			ra(&*(a), 1);
		else
			sa(*a, 1);
	}
	else if ((*a)->data > (*a)->next->next->data)
		rra(&*(a), 1);
	else
	{
		sa(*a, 1);
		ra(&*(a), 1);
	}
}

void	sort_two(t_list **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(*(a), 1);
}

void	printnode(t_list *s, char c)
{
	while (s)
	{
		printf("stack %c after===>%d\n", c, s->data);
		s = s->next;
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
	printnode(a,'a');
	freelist(&a, &b);
	return (0);
}