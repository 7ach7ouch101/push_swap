/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:38:45 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/15 22:19:10 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i] != '\0')
	{
		j = i + 1;
		while (input[j] != '\0')
		{
			if (ft_strcmp(input[i], input[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int(char **input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (ft_atoi(input[i]) > 2147483647 || ft_atoi(input[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

char	*join_str(int ac, char**av)
{
	char	*str;
	int		j;

	j = 2;
	ac--;
	str = ft_strjoin(av[1], " ");
	while (ac--)
	{
		str = ft_strjoin(str, av[j]);
		if (ac == 1)
		{
			str = ft_strjoin(str, "\0");
			break ;
		}
		str = ft_strjoin(str, " ");
		j++;
	}
	return (str);
}

int	parse(int ac, char **av, struct Node **a)
{
	char	*str;
	char	**str1;
	int		i;

	i = 0;
	str = join_str(ac, av);
	str1 = ft_split(str, ' ');
	i = ft_strlen(str1);
	if (!check_error(str1) || is_dup(str1) || check_int(str1) || ac <= 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i >= 0)
	{
		(*a) = fillnodes(&(*a), str1[i]);
		i--;
	}
	return (1);
}
