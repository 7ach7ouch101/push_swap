#include "push_swap.h"

void    sb(struct Node *b)
{
    if(lstsize(b) == 0)
		return ;
    int data;

    if(b->next == NULL)
        return ;
    data = b->data;
    b->data = b->next->data;
    b->next->data = data;
    write(1,"sb\n",3);
}