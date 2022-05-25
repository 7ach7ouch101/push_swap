/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:11:15 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/23 23:48:24 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	words(const char *str, char c)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i + 1] == c)
			|| (str[i + 1] == '\0' && str[i] != c))
			u++;
		i++;
	}
	return (u);
}

void	*freee(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static	char	**fillarr(char **p, const char *s, char c)
{
	int	j;
	int	e;

	e = 0;
	while (*s)
	{
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (j > 0)
		{
			p[e] = (char *)malloc((j + 1) * sizeof(char));
			if (!p)
				return (freee(p));
			ft_memcpy(p[e], s, j);
			p[e][j] = '\0';
			e++;
			s = s + j;
		}
		else
			s++;
	}
	p[e] = NULL;
	return (p);
}

char	**ft_split(const char *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = (char **)malloc(((words(s, c) + 1) * sizeof(char *)));
	if (!p)
		return (NULL);
	p = fillarr(p, s, c);
	return (p);
}

long	ft_atoi(char *str)
{
	long	num;
	int		neg;
	int		i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
