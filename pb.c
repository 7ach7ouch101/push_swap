#include "push_swap.h"

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