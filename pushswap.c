#include<stdio.h>
#include<unistd.h>
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
int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
static  int ft_isdigit(char *av, int ac)
{
    int i;

    i = 0;
	while (av[i] != '\0')
    {
        if(av[i] >= '0' && av[i] <= '9')
            i++;
        else
            return 0;
    }
    return 1;
}
int check_error(int ac, char **av)
{
    int i;

    i = 1;
    while(i < ac)
    {
        if(!ft_isdigit(av[i],ac) || av[i][0] == '\0')
            return 0;
        i++;
    }
    return (1);
}
int is_dup(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if(ft_strcmp(av[i],av[j]) == 0)
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}
int check_int(char **av, int ac)
{
    int i;

    i = 1;
    while(i < ac)
    {
        if(ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
            return 1;
        i++;
    }
    return 0;
}
struct Node *fillnodes(struct Node *head, char *av1, char *av2)
{
    struct Node *sec;
    if(head->next == NULL)
    {
        head->data = ft_atoi(av1);
        head->next = NULL;
    }
    sec = malloc(sizeof(Node));
    sec->data = ft_atoi(av2);
    sec->next = head;
    return sec;
}
int main(int ac, char **av)
{
    struct Node *a = NULL;
    int i;
    a = malloc(sizeof(Node));
    i = (ac - 1);

    if(!check_error(ac,av) || is_dup(av,ac) || check_int(av,ac))
    {
        write(1, "Error\n", 6);
        return 0;
    }
    ac--;
    while(i > 0)
        a = fillnodes(a,av[ac],av[i--]);
    while(a)
    {
        printf("%d",a->data);
        a->next;
    }
    return 0;
}