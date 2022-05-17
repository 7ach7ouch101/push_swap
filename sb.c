/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:11:27 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/16 22:06:06 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(struct Node *b)
{
	int	data;

	if (b->next == NULL)
		return ;
	data = b->data;
	b->data = b->next->data;
	b->next->data = data;
	write(1, "sb\n", 3);
}
