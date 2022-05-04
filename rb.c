#include "push_swap.h"

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