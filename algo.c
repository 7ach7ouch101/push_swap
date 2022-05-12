#include "push_swap.h"

void    sort_arr(int *str)
{
	int j;
	int i;
	int n;
	int tmp;

	j = 0;
	i = 0;
	while(j < i)
    {
        n = j + 1;
    
        while(n < i)
        {
            if(str[j] > str[n])
            {
                tmp = str[j];
                str[j] = str[n];
                str[n] = tmp;
            }
            n++;
        }
        j++;
    }
}
void    fill_array(struct Node *a, int *str)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(a)
    {
        str[i] = a->data;
        a = a->next;
        i++;
    }
	sort_arr(str);
}

void    above_five(struct Node **a, struct Node **b)
{
    int var1;
    int var2;
    int *str;
    int start;
    int first;

    while(lstsize(*a) != 0)
    {
        first = 0;
        start = 1;
        str = malloc(lstsize(*a) * sizeof(int));
        fill_array(*a,str);
        var1 = str[lstsize(*a) / 3];
        var2 = str[(lstsize(*a) / 3) / 2];
        while(*a && (start || first != (*a)->data))
        {
            if((*a)->data <= var1)
            {
                if((*a)->data <= var2)
                {
                    pb(&*(a),&*(b));
                    rb(&*(b));
                }
                else
                    pb(&*(a),&*(b));
            }
            else
            {
                if(start)
                {
                    first = (*a)->data;
                    start = 0;
                }
                ra(&*(a));
            }
        }
            free(str);
    }
    while((*b))
        sort_b(&*(a),&*(b));
}