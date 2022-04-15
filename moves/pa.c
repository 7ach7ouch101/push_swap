


#include "../push_swap.h"

void	pa(struct Node **a, struct Node **b)
{
	if(b == NULL)
		return ;
	struct Node *tmp;
	tmp = *b;
	*b = tmp->next;
    tmp->next = *a;
	*a = tmp;
}