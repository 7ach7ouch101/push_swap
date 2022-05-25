/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:38:45 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/25 01:41:31 by mmeziani         ###   ########.fr       */
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
	char *tmp;
	int		j;

	j = 2;
	ac--;
	str = ft_strjoin(av[1], " ");
	tmp = str;
	while (ac--)
	{
		//check(tmp);
		str = ft_strjoin(tmp, av[j]);
		free(tmp);
		if (ac == 1)
		{
			tmp = str;
			str = ft_strjoin(str, "\0");
			free(tmp);
			break ;
		}
		tmp = ft_strjoin(str, " ");
		free(str);
		j++;
	}
	return (str);
}

int	parse(int ac, char **av, t_list **a)
{
	char	*str;
	char	**str1;
	int		i;

	//check(*av);
	i = 0;
	// if (ac == 2)
	// 	str1 = ft_split(av[1], ' ');
	// else
	// {
		str = join_str(ac, av);
		str1 = ft_split(str, ' ');
		free(str);
	// }
	i = ft_strlen(str1);
	if (!check_error(str1) || is_dup(str1) || check_int(str1) || (ac <= 2 && i == 0))
	{
    	write(2, "Error\n", 6);
	    exit (1);
	}
	while (i >= 0)
	{
		(*a) = fillnodes(&(*a), str1[i]);
		i--;
	}
	return (freee(str1),1);
}
