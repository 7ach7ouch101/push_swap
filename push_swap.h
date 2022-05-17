#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node *next;
} Node;

void	pa(struct Node **a, struct Node **b);
void	pb(struct Node **a, struct Node **b);
void	    ra(struct Node **a);
void	rb(struct Node **b);
void	rra(struct Node **a);
void	rrb(struct Node **b);
void    sa(struct Node *head);
void    sb(struct Node *head);
int     lstsize(struct Node *a);
long	ft_atoi(char *str);
char	**ft_split(const char *s, char c);
int     ft_strlen(char **str);
int	    ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int     check_error(char **input);
void    above_five(struct Node **a, struct Node **b);
void    fa(struct Node *a, int *str);
void    sort_arr(int *str, int i);
void    push_to_b(struct Node **a, struct Node **b);
int	    check_for_location(int size, struct Node *b);
int	    big_instack(struct Node *b);
int     parse(int ac, char **av,struct Node **a);
char    *join_str(int ac, char**av);
int     check_int(char **input);
int     is_dup(char **input);
int     is_sorted(struct Node *a);
void    freelist(struct Node **a, struct Node **b);
struct Node *fillnodes(struct Node **head, char *str);
void	*ft_memcpy(void	*dst, const void *src, size_t n);
char	*merge(char *s1, char *s2, char *p);
#endif