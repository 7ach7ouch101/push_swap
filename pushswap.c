#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "push_swap.h"
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
void	pa(struct Node **a, struct Node **b)
{
    if((*b) == NULL)
    {
        return ;
    }
    
	struct Node *tmp;
	tmp = *b;
	*b = tmp->next;
    tmp->next = *a;
	*a = tmp;
	write(1,"pa\n",3);
}
void	pb(struct Node **a, struct Node **b)
{
    if((*a) == NULL)
    {
        return ;
    }

	struct Node *tmp;
    tmp = *a;
	*a = tmp->next;
    tmp->next = *b;
	*b = tmp;
    write(1,"pb\n",3);
}
void	ra(struct Node **a)
{
    struct Node *tmp;
    struct Node *tmp2;

    tmp = *a;
    tmp2 = tmp->next;
    while((*a)->next)
        *a = (*a)->next;
    (*a)->next = tmp;
    (*a)->next->next = NULL;
    *a = tmp2;
    write(1,"ra\n",3);
}
void	rb(struct Node **b)
{
    if (lstsize(*b) <= 1)
        return ;
    struct Node *tmp;
    struct Node *tmp2;

    tmp = *b;
    tmp2 = tmp->next;
    while((*b)->next)
        *b = (*b)->next;
    (*b)->next = tmp;
    (*b)->next->next = NULL;
    *b = tmp2;
    write(1,"rb\n",3);
}
void	rra(struct Node **a)
{
	struct Node *tmp2;
	struct Node *tmp;
	tmp = *a;
	while((*a)->next->next)
		*a = (*a)->next;
	tmp2 = (*a)->next;
	(*a)->next->next = tmp;
	(*a)->next = NULL;
	*a = tmp2;
	write(1,"rra\n",4);
}
void	rrb(struct Node **b)
{
    if (lstsize(*b) <= 1)
    {
        return ;
    }
    
	struct Node *tmp2;
	struct Node *tmp;
	tmp = *b;
	while((*b)->next->next)
		*b = (*b)->next;
	tmp2 = (*b)->next;
	(*b)->next->next = tmp;
	(*b)->next = NULL;
	*b = tmp2;
	write(1,"rrb\n",4);
}
void    sa(struct Node *a)
{
    if(lstsize(a) == 0)
		return ;
    int data;

    if(a->next == NULL)
        return ;
    data = a->data;
    a->data = a->next->data;
    a->next->data = data;
    write(1,"sa\n",3);
}
void    sb(struct Node *b)
{
    if(lstsize(b) == 0)
		return ;
    int data;

    if(b->next == NULL)
        return ;
    data = b->data;
    b->data = b->next->data;
    b->next->data = data;
    write(1,"sb\n",3);
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
static  int ft_isdigit(char *av)
{
    int i;

    i = 0;
    if(av[i] == '-')
    {
        i++;
    }
    
	while (av[i] != '\0')
    {
        if(av[i] >= '0' && av[i] <= '9')
            i++;
        else
            return 0;
    }
    return 1;
}
int check_error(int ac, char **av)
{
    int i;

    i = 1;
    while(i < ac)
    {
        if(!ft_isdigit(av[i]) || av[i][0] == '\0')
            return 0;
        i++;
    }
    return (1);
}
int is_dup(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if(ft_strcmp(av[i],av[j]) == 0)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}
int check_int(int ac, char **av)
{
    int i;

    i = 1;
    while(i < ac)
    {
        if(ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
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
int main(int ac, char **av)
{
    int i;
    struct Node *a;
    struct Node *b;
    b = NULL;
    a = NULL;
    i = (ac - 1);

    if(!check_error(ac,av) || is_dup(ac,av) || check_int(ac,av))
    {
        write(1, "Error\n", 6);
        return 0;
    }
    while((i - 1) >= 0)
    {
        a = fillnodes(a, av[i]);
        i--;
    }
    /*if(lstsize(a) == 3)
        sort_three(&a);
    else*/
    above_five(&a,&b);
    //printnode(a, 'a');
    freelist(&a,&b);
    return 0;
}