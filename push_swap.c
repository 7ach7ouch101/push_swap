#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "push_swap.h"
#include<string.h>
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
static  int ft_isdigit(char *input)
{
    int i;

    i = 0;
    if(input[i] == '-')
    {
        i++;
    }
    
	while (input[i] != '\0')
    {
        if(input[i] >= '0' && input[i] <= '9')
            i++;
        else
            return 0;
    }
    return 1;
}
int check_error(char *input)
{
    int i;

    i = 0;
    while(input[i] != '\0')
    {
        if(input[i] )
            return 0;
        i++;
    }
    return (1);
}
int is_dup(int ac, char *input)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if(ft_strcmp(&input[i],&input[j]) == 0)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}
int check_int(int ac, char *input)
{
    int i;

    i = 1;
    while(i < ac)
    {
        if(ft_atoi(&input[i]) > 2147483647 || ft_atoi(&input[i]) < -2147483648)
            return 1;
        i++;
    }
    return 0;
}
struct Node *fillnodes(struct Node *head, char *av2)
{
    struct Node *sec;
    sec = malloc(sizeof(Node));
    sec->data = ft_atoi(av2);
    sec->next = head;
    return sec;
}
void    sort_three(struct Node **a)
{
    if((*a)->data > (*a)->next->data && (*a)->next->data < (*a)->next->next->data)
        sa(*a);
    else if((*a)->data > (*a)->next->data && (*a)->data > (*a)->next->next->data)
    {
        if((*a)->next->data > (*a)->next->next->data)
        {
            sa(*a);
            rra(&*(a));
        }
        else
            ra(&*(a));
    }
    else if((*a)->data < (*a)->next->data && (*a)->data < (*a)->next->next->data)
    {
        sa(*a);
        ra(&*(a));
    }
    else
        rra(&*(a));
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

    while(lstsize(*a) != 0)
    {
        str = malloc(lstsize(*a) * sizeof(int));
        fill_array(*a,str);
        var1 = str[lstsize(*a) / 3];
        var2 = str[(lstsize(*a) / 3) / 2];
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
            ra(&*(a));
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
char    *parse(int ac, char **av)
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
    return tmp;
}
int main(int ac, char **av)
{
    //int i;
    char *str;
    struct Node *a;
    struct Node *b;
    b = NULL;
    a = NULL;
    //i = (ac - 1);
    str = parse(ac,av);

    if(!check_error(ac,str) || is_dup(ac,str) || check_int(ac,str))
    {
        write(1, "Error\n", 6);
        return 0;
    }
    /*while((i - 1) >= 0)
    {
        a = fillnodes(a, av[i]);
        i--;
    }
    if(lstsize(a) == 3)
        sort_three(&a);
    else
    above_five(&a,&b);
    printnode(a, 'a');
    freelist(&a,&b);*/
    return 0;
}