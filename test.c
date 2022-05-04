#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

static	char	*merge(char *s1, char *s2, char *p)
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

char	*ft_strjoin(char *s1, char *s2)
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
int main(int ac, char **av)
{
    char *tmp;
    int j;
    j = 2;
    ac--;
	tmp = ft_strjoin(av[1], " ");
    while(ac)
    {
        tmp = ft_strjoin(tmp,av[j]);
        ac--;
		if(ac == 1)
		{
			tmp = ft_strjoin(tmp, "\0");
			break ;
		}
		tmp = ft_strjoin(tmp," ");
        j++;
    }
}