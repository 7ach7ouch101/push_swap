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

char	*get_next_line(int fd)
{
	char	str[8000000];
	int		i;
	char	buff[1];
	int		byte;

	byte = read(fd, buff, 1);
	i = 0;
	while (byte > 0)
	{
		str[i++] = buff[0];
		if (buff[0] == '\n')
			break ;
		byte = read(fd, buff, 1);
	}
	str[i] = '\0';
	if (str[0] == '\0')
		return (0);
	return (ft_strdup(str));
}

void	check2(t_list **a, t_list **b, char *str)
{
	if (!ft_strcmp("pa\n", str))
		pa(a, b, 0);
	else if (!ft_strcmp("rrr\n", str))
		rrr(a, b);
	else if (!ft_strcmp("ss\n", str))
		ss(a, b);
	else if (!ft_strcmp("rr\n", str))
		rr(a, b);
	else
		ft_putstr("Error\n");
}

void	check(t_list **a, t_list **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!ft_strcmp("rra\n", str))
			rra(a, 0);
		else if (!ft_strcmp("ra\n", str))
			ra(a, 0);
		else if (!ft_strcmp("sa\n", str))
			sa(a, 0);
		else if (!ft_strcmp("rrb\n", str))
			rrb(b, 0);
		else if (!ft_strcmp("rb\n", str))
			rb(b, 0);
		else if (!ft_strcmp("sb\n", str))
			sb(b, 0);
		else if (!ft_strcmp("pb\n", str))
			pb(a, b, 0);
		else
			check2(a, b, str);
		str = get_next_line(0);
	}
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
	check(a,b);
	if(is_sorted(a) && lstsize(b) == 0)
		write(1, "OK",2);
	else
		write(1, "KO", 2);
}