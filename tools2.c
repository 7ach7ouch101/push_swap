/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:33:10 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/23 17:10:14 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*merge(char *s1, char *s2, char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strlen2(char *s)
{
	int	i;

	if (!s)
		exit(1);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		a;
	int		b;

	if (!s1 || !s2)
		exit(1);
	a = ft_strlen2(s1);
	b = ft_strlen2(s2);
	p = malloc((a + b) + 1);
	if (!p)
		return (NULL);
	p = merge(s1, s2, p);
	return (p);
}

int	lstsize(t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (((unsigned char) s1[i] - (unsigned char) s2[i]));
}
