/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:30:30 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/24 00:02:26 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves(char *move, t_list **a, t_list **b)
{

	if (ft_strcmp(move, "sa\n") == 0)
		sa(*(a));
	else if (ft_strcmp(move, "sb\n") == 0)
		sb(*(b));
	/*else if (ft_strcmp(move, "ss\n") == 0)
		ft_swap_ss(a, b);*/
	else if (ft_strcmp(move, "pa") == 0)
		pa(&*(a), &*(b));
	else if (ft_strcmp(move, "pb") == 0)
		pb(&*(a), &*(b));
	else if (ft_strcmp(move, "ra") == 0)
		ra(&*(a));
	else if (ft_strcmp(move, "rb") == 0)
		rb(&*(b));
	/*else if (ft_strcmp(move, "rr\n") == 0)
		ft_rotate_rr(a, b);*/
	else if (ft_strcmp(move, "rra") == 0)
		rra(&*(a));
	else if (ft_strcmp(move, "rrb") == 0)
		rrb(&*(b));
	/*else if (ft_strcmp(move, "rrr\n") == 0)
		ft_revrotate_rrr(a, b);*/
	else
		write(1,"Error\n",6);
	return ;
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char		*buff;
	int			ret;

	ret = 1;
	a = NULL;
	b = NULL;
	if (ac <= 2 || parse(ac, av, &a) == 0)
		return (0);
	while (ret != 0)
	{
		buff = malloc(6 * sizeof(char));
		ret = read(1, buff, 4);
		//buff[4] = '\0';
		moves(buff, &a, &b);
		free(buff);
	}
	while(a)
	{
		printf("stack  after===>%d\n",a->data);
		a = a->next;
	}
	if(is_sorted(a) && lstsize(b) == 0)
		write(1, "OK",2);
	else
		write(1, "KO", 2);
}