#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
}Node;
long	ft_atoi(char *str)
{
	int neg;
	long num;
	int i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
struct Node  *newnode(struct Node *head,char *av)
{
    struct Node *sec;
    sec = malloc(sizeof(Node));
    sec->data = ft_atoi(av);
    sec->next = head;
    return sec;
}
int main(int ac, char **av)
{
    int i;
    i = ac - 1;
    int j;
    j = 0;
    struct Node *head;
    head = NULL;
    head = malloc(sizeof(Node));
    head->data = ft_atoi(av[i--]);
    head->next = NULL;
    ac--;
    while(i > 0)
    {
        head = newnode(head,av[i]);
        i--;
    }
    while (head)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
    return 0;
}