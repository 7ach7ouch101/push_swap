#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "push_swap.h"
#include<string.h>
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
static void	*freee(char **p)
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
			memcpy(p[e], s, j);
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
int lstsize(struct Node *a)
{
    int i;

    i = 0;
    while(a)
    {
        i++;
        a = a->next;
    }
    return i;
}
long	ft_atoi(char *str)
{
	int neg;
	long num;
	int i;

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
int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
int check_error(char **input)
{
    int i;
    int j;

    i = 0;
	while(input[i] != '\0')
	{
        j = 0;
        if(input[i][j] == '-' || input[i][j] == '+')
            j++;
        while(input[i][j] != '\0')
        {
            if(input[i][j] >= '0' && input[i][j] <= '9')
               j++;     
            else
                return 0;
        }
        i++;
	}
    return (1);
}
int is_dup(char **input)
{
    int i;
    int j;

    i = 0;
    while(input[i] != '\0')
    {
        j = i + 1;
        while(input[j] != '\0')
        {
            if(ft_strcmp(input[i],input[j]) == 0)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}
int check_int(char **input)
{
    int i;

    i = 0;
    while(input[i] != '\0')
    {
        if(ft_atoi(input[i]) > 2147483647 || ft_atoi(input[i]) < -2147483648)
            return 1;
        i++;
    }
    return 0;
}
void    sort_three(struct Node **a)
{
    if((*a)->data > (*a)->next->data)
        if((*a)->next->data > (*a)->next->next->data)
        {
            sa(*a);
            rra(&*(a));
        }
        else if((*a)->data > (*a)->next->next->data)
            ra(&*(a));
        else
            sa(*a);
    else if((*a)->data > (*a)->next->next->data)
        rra(&*(a));
    else
    {
        sa(*a);
        ra(&*(a));
    }
}
int indexofmin(struct Node *a)
{
    int index;
    int i;
    i = 0;
    index = 0;
    while(a)
    {
        if(a->next != NULL)
        {
            if(a->data < a->next->data)
                index = i;
        }
        a = a->next;
        i++;
    }
    return index;
}

void    fill_array(struct Node *a, int *str)
{
    int i;
    int j;
    int n;
    int tmp;

    j = 0;
    i = 0;
    while(a)
    {
        str[i] = a->data;
        a = a->next;
        i++;
    }
    while(j < i)
    {
        n = j + 1;
    
        while(n < i)
        {
            if(str[j] > str[n])
            {
                tmp = str[j];
                str[j] = str[n];
                str[n] = tmp;
            }
            n++;
        }
        j++;
    }
}
int	big_instack(struct Node *b)
{
	int	tmp;

	tmp = (b)->data;
	while (b)
	{
		if (tmp < (b)->data)
			tmp = (b)->data;
		b = (b)->next;
	}
	return (tmp);
}
int	check_for_location(int size, struct Node *b)
{
	size = size / 2;
	while (size && b)
	{
		if (b->data == big_instack(b))
			return (1);
		b = (b)->next;
		size--;
	}
	return (0);
}
void    sort_b(struct Node **a, struct Node **b)
{
	if (check_for_location(lstsize(*b), *b) == 1)
	{
		if ((*b)->data == big_instack(*b))
			pa(&*(a),&*(b));
		else if ((*b)->next->data == big_instack(*b))
		{
			sb(*(b));
			pa(&*(a),&*(b));
		}
		else
			rb(&*(b));
	}
	else if ((*b)->next == NULL)
		pa(&*(a),&*(b));
	else
		rrb(&*(b));
}
void    above_five(struct Node **a, struct Node **b)
{
    int var1;
    int var2;
    int *str;
    int start;
    int first;

    while(lstsize(*a) != 0)
    {
        first = 0;
        start = 1;
        str = malloc(lstsize(*a) * sizeof(int));
        fill_array(*a,str);
        var1 = str[lstsize(*a) / 3];
        var2 = str[(lstsize(*a) / 3) / 2];
        while(*a && (start || first != (*a)->data))
        {
            if((*a)->data <= var1)
            {
                if((*a)->data <= var2)
                {
                    pb(&*(a),&*(b));
                    rb(&*(b));
                }
                else
                    pb(&*(a),&*(b));
            }
            else
            {
                if(start)
                {
                    first = (*a)->data;
                    start = 0;
                }
                ra(&*(a));
            }
        }
            free(str);
    }
    while((*b))
        sort_b(&*(a),&*(b));
}
void    freelist(struct Node **a, struct Node **b)
{
    struct Node *tmp;
    struct Node *tmp1;
    while (*a)
    {
       tmp = *a;
       (*a) = (*a)->next;
       free(tmp);
    }
    while(*b)
    {
       tmp1 = *b;
       (*b) = (*b)->next;
       free(tmp1);
    }
}
void printnode(struct Node *s, char c)
{
    while(s)
    {
        printf("stack %c after===>%d\n", c,s->data);
        s = s->next;
    }
}
struct Node *fillnodes(struct Node **head, char *str)
{
    struct Node *sec;
    sec = malloc(sizeof(Node));
    sec->data = ft_atoi(str);
    sec->next = (*head);
    return sec;
}
char *join_str(int ac, char**av)
{
    char *str;
    int j;

    j = 2;
    ac--;
	str = ft_strjoin(av[1], " ");
    while(ac--)
    {
        str = ft_strjoin(str,av[j]);
		if(ac == 1)
		{
			str = ft_strjoin(str, "\0");
			break ;
		}
		str = ft_strjoin(str," ");
        j++;
    }
    return str;
}
int ft_strlen(char **str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    i--;
    return i;
}

int    parse(int ac, char **av,struct Node **a)
{
    char *str;
    char **str1;
    int i;

    i = 0;
    str = join_str(ac,av);
    str1 = ft_split(str,' ');
    i = ft_strlen(str1);
    if(!check_error(str1) || is_dup(str1) || check_int(str1))
    {
        write(1, "Error\n", 6);
        return 0;
    }
    while(i >= 0)
    {
        (*a) = fillnodes(&(*a),str1[i]);
        i--;
    }
    return 1;
}
int is_sorted(struct Node *a)
{
    int data;

    data = a->data;
    a = a->next;
    while(data < a->data)
    {
        data = a->data;
        if(a->next->next == NULL && data < a->next->data)
            return 1;
        a = a->next;
    }
    return 0;
}
int	small_instack(struct Node *a)
{
	int	tmp;

	tmp = (a)->data;
	while (a)
	{
		if (tmp > (a)->data)
			tmp = (a)->data;
		a = (a)->next;
	}
	return (tmp);
}
void    sort_five(struct Node **a, struct Node **b)
{
	while (*a)
	{
		if (lstsize(*b) == 2)
			break ;
		if ((*a)->data == small_instack(*a))
			pb(&*(a),&*(b));
		else
			ra(&*(a));
	}
	while (lstsize(*a) == 3)
	{
		if ((*a)->data > (*a)->next->next->data)
			ra(&*(a));
		else if ((*a)->data > (*a)->next->data)
			sa(*(a));
		else if ((*a)->next->data > (*a)->next->next->data)
			rra(&*(a));
		else
			break ;
	}
	while (*b)
		pa(&*(a),&*(b));
}
void    sort_two(struct Node **a)
{
    if((*a)->data > (*a)->next->data)
        sa(*(a));
}
int main(int ac, char **av)
{
    struct Node *a;
    struct Node *b;

    b = NULL;
    a = NULL;
    if(ac <= 2 || parse(ac,av,&a) == 0 || is_sorted(a))
        return 0;
    if(lstsize(a) == 2)
        sort_two(&a);
    else if(lstsize(a) == 3)
        sort_three(&a);
    else if(lstsize(a) == 5)
        sort_five(&a,&b);
    else
        above_five(&a,&b);
    printnode(a, 'a');
    freelist(&a,&b);
    return 0;
}