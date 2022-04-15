#include "../push_swap.h"

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
}