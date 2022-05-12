#include "push_swap.h"

int check_error(char **input)
{
    int i;
    int j;

    i = 0;
	while(input[i] != '\0')
	{
        j = 0;
        if(input[i][j] == '-' || input[i][j] == '+')
            j++;
        while(input[i][j] != '\0')
        {
            if(input[i][j] >= '0' && input[i][j] <= '9')
               j++;     
            else
                return 0;
        }
        i++;
	}
    return (1);
}

int is_sorted(struct Node *a)
{
    int data;

    data = a->data;
    a = a->next;
    while(data < a->data)
    {
        data = a->data;
        if(a->next->next == NULL && data < a->next->data)
            return 1;
        a = a->next;
    }
    return 0;
}

struct Node *fillnodes(struct Node **head, char *str)
{
    struct Node *sec;
    sec = malloc(sizeof(Node));
    sec->data = ft_atoi(str);
    sec->next = (*head);
    return sec;
}

void    freelist(struct Node **a, struct Node **b)
{
    struct Node *tmp;
    struct Node *tmp1;
    while (*a)
    {
       tmp = *a;
       (*a) = (*a)->next;
       free(tmp);
    }
    while(*b)
    {
       tmp1 = *b;
       (*b) = (*b)->next;
       free(tmp1);
    }
}