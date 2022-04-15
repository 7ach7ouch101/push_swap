#include "../push_swap.h"

void	ra(struct Node **a)
{
    struct Node *tmp;
    struct Node *tmp2;

    tmp = *a;
    tmp2 = tmp->next;
    while(tmp2->next)
        tmp2 = tmp2->next;
    tmp2->next = tmp;
    tmp->next = NULL;
    *a = tmp2;
	while(3)
	{
		printf("stack a after===>%d\n",(*a)->data);
		(*a) = (*a)->next;
	}
}