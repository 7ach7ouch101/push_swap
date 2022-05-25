#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <string.h>

typedef struct t_Node
{
    int data;
    struct t_Node *next;
} t_list;
typedef struct s_vars
{
	int	var1;
	int	var2;
	int	*ar;
	int	first;
	int	start;
}t_vars;

//void	printnode(t_list *s, char c);
void	*freee(char **p);
void	pa(t_list **a, t_list **b, int s);
void	pb(t_list **a, t_list **b, int s);
void	ra(t_list **a, int s);
void	rb(t_list **b, int s);
void	rra(t_list **a, int s);
void	rrb(t_list **b, int s);
void    sa(t_list *head, int s);
void    sb(t_list *head, int s);
void    ss(t_list *a, t_list *b);
void    rr(t_list **a, t_list **b);
void    rrr(t_list **a, t_list **b);
int     lstsize(t_list *a);
long	ft_atoi(char *str);
char	**ft_split(const char *s, char c);
int     ft_strlen(char **str);
int	    ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int     check_error(char **input);
int	    *sort_stack(t_list *lst);
void	push_to_a(t_list **a, t_list **b, t_vars v);
void	push_to_b(t_list **a, t_list **b);
int	    check_for_location(int size, t_list *b);
int	    big_instack(t_list *b);
int     parse(int ac, char **av,t_list **a);
char    *join_str(int ac, char**av);
int     check_int(char **input);
int     is_dup(char **input);
int     is_sorted(t_list *a);
void    freelist(t_list **a, t_list **b);
t_list  *fillnodes(t_list **head, char *str);
void	*ft_memcpy(void	*dst, const void *src, size_t n);
char	*merge(char *s1, char *s2, char *p);
void	above_five(t_list **a, t_list **b);
void    p_error(void);
//void    check(char *s);
#endif