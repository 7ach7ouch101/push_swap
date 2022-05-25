/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:49:56 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/23 21:58:07 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i] != '\0')
	{
		j = 0;
		if (input[i][j] == '-' || input[i][j] == '+')
			j++;
		while (input[i][j] != '\0')
		{
			if (input[i][j] >= '0' && input[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_list *a)
{
	int	data;

	if (!a)
		return (0);
	data = a->data;
	a = a->next;
	while (data < a->data)
	{
		data = a->data;
		if (a->next->next == NULL && data < a->next->data)
			return (1);
		a = a->next;
	}
	return (0);
}

t_list	*fillnodes(t_list **head, char *str)
{
	t_list	*sec;

	sec = malloc(sizeof(t_list));
	sec->data = ft_atoi(str);
	sec->next = (*head);
	return (sec);
}

void	freelist(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;

	while (*a)
	{
		tmp = *a;
		(*a) = (*a)->next;
		free(tmp);
	}
	while (*b)
	{
		tmp1 = *b;
		(*b) = (*b)->next;
		free(tmp1);
	}
}
