#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<stdio.h>

struct Node 
{
    int data;
    struct Node *next;
} Node;
void	pa(struct Node **a, struct Node **b);
void	ra(struct Node **a);
void	rra(struct Node **a);
void    sa(struct Node *head);

#endif