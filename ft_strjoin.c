/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeziani <mmeziani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:29:30 by mmeziani          #+#    #+#             */
/*   Updated: 2022/05/04 14:29:50 by mmeziani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

static	char	*merge(char const *s1, char const *s2, char *p)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		a;
	int		b;

	if (!s1 || !s2)
		return (NULL);
	a = strlen(s1);
	b = strlen(s2);
	p = malloc((a + b) + 1);
	if (!p)
		return (NULL);
	p = merge(s1, s2, p);
	return (p);
}	
