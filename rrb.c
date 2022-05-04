#include "push_swap.h"

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