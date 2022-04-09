#include<stdio.h>
#include<stdlib.h>



struct Node 
{
    int data;
    struct Node *next;
} Node;
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
void    sa(struct Node *head)
{
    int data;

    if(head->next == NULL)
        return ;
    data = head->data;
    head->data = head->next->data;
    head->next->data = data;
}
/*void	pa(struct Node **a, struct Node **b)
{
	if(b == NULL)
		return ;
	struct Node *tmp;
	tmp = *b;
	*b = tmp->next;
    tmp->next = *a;
	*a = tmp;
}*/
void	ra(struct Node **a)
{
	struct Node *tmp;
	struct Node *tmp2;

	tmp = *a;
	tmp2 = (*a)->next;
	while((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
	*a = tmp2;
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
}
void	test(struct Node **a, struct Node **b)
{
	printf("test %p\n", *a);
	printf("test %p\n", &a);
}
int main(int ac, char **av)
{
    struct Node *a = NULL;
    struct Node *b = NULL;
    b = malloc(sizeof(struct Node));
    a = malloc(sizeof(struct Node));
    int i;
    ac--;
    i = (ac - 1);
    while(i > 0)
        a = fillnodes(a,av[ac],av[i--]);
	i = (ac - 1);
	while(i > 0)
        b = fillnodes(b,av[ac],av[i--]);
	//sa(a);
	//pa(&a,&b);
	//ra(&a);
	rra(&a);
	//test(&a,&b);
	while(a)
	{
		printf("stack a ===>%d\n",a->data);
		a = a->next;
	}
	
    return 0;
}