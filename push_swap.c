#include "push_swap.h"

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

void    sort_two(struct Node **a)
{
    if((*a)->data > (*a)->next->data)
        sa(*(a));
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