
   
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

struct Node 
{
    int data;
    struct Node *next;
} Node;
void	pa(struct Node **a, struct Node **b);
void	pb(struct Node **a, struct Node **b);
void	ra(struct Node **a);
void	rb(struct Node **b);
void	rra(struct Node **a);
void	rrb(struct Node **b);
void    sa(struct Node *head);
void    sb(struct Node *head);
int lstsize(struct Node *a);
#endif