#include "push_swap.h"

void	rra(struct Node **a)
{
    if (lstsize(*a) <= 1)
    {
        return ;
    }
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