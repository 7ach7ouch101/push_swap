#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct Node 
{
    int data;
    struct Node *next;
} Node;
void	pa(struct Node **a, struct Node **b)
{
	if((*b)->next == NULL)
		return ;
	struct Node *tmp;
	tmp = *b;
	*b = tmp->next;
    tmp->next = *a;
	*a = tmp;
	write(1,"pa\n",3);
}
void	pb(struct Node **a, struct Node **b)
{
	if((*a)->next == NULL)
		return ;
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
void    sa(struct Node *head)
{
    int data;

    if(head->next == NULL)
        return ;
    data = head->data;
    head->data = head->next->data;
    head->next->data = data;
    write(1,"sa\n",3);
}
void    sb(struct Node *head)
{
    int data;

    if(head->next == NULL)
        return ;
    data = head->data;
    head->data = head->next->data;
    head->next->data = data;
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
struct Node *fillnodes(struct Node *head, char *av1, char *av2)
{
    struct Node *sec;
    if(head->next == NULL)
    {
        (head->data) = ft_atoi(av1);
        (head->next) = NULL;
    }
    sec = malloc(sizeof(Node));
    sec->data = ft_atoi(av2);
    sec->next = head;
    return sec;
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
int is_sorted(struct Node *a)
{
    while(a->next)
    {
        if(a->data < a->next->data)
            a = a->next;
        else
            return 0;
    }
    return 1;
}
int get_indexofmin(struct Node *a)
{
    int index;
    int tmp;
    int i;

    tmp = a->data;
    index = 0;
    i = 0;
    while(a)
    {
        if(a->next)
        {
            if(tmp > a->next->data)
            {
                tmp = a->next->data;
                index = (i + 1);
            }
        }
        a = a->next;
        i++;
    }
    return index;
}
void    sort_b(struct Node **a, struct Node **b)
{
    int index;

    while(!is_sorted(*b))
    {
        index = get_indexofmin(*b);
        if(index <= (lstsize(*b) / 2))
            while(index)
            {
                rb(&*(b));
                index--;
            }
        else
            rrb(&*(b));
        pa(&*(a),&*(b));
    }
    while((*b)->next)
        pa(&*(a),&*(b));
}
void    above_five(struct Node **a, struct Node **b)
{
    int var1;
    int var2;
    int *str;

    while(lstsize(*a) != 1)
    {
        str = malloc(lstsize(*a));
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
    //sort_b(&*(a),&*(b));
}
int     main(int ac, char **av)
{
    int j;
    j = 0;
    int i;
    struct Node *a;
    struct Node *b;
    int *str;
    b = malloc(sizeof(Node));
    a = malloc(sizeof(Node));
    b->next = NULL;
    a->next = NULL;
    i = (ac - 1);
    ac--;

    while((i - 1) > 0)
    {
        i--;
        a = fillnodes(a,av[ac],av[i]);
    }

    above_five(&a,&b);

    while(b)
	{
		printf("stack b after===>%d\n",b->data);
		b = b->next;
	}

}