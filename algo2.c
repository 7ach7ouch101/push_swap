#include "push_swap.h"

int	big_instack(struct Node *b)
{
	int	tmp;

	tmp = (b)->data;
	while (b)
	{
		if (tmp < (b)->data)
			tmp = (b)->data;
		b = (b)->next;
	}
	return (tmp);
}
int	check_for_location(int size, struct Node *b)
{
	size = size / 2;
	while (size && b)
	{
		if (b->data == big_instack(b))
			return (1);
		b = (b)->next;
		size--;
	}
	return (0);
}
void    sort_b(struct Node **a, struct Node **b)
{
	if (check_for_location(lstsize(*b), *b) == 1)
	{
		if ((*b)->data == big_instack(*b))
			pa(&*(a),&*(b));
		else if ((*b)->next->data == big_instack(*b))
		{
			sb(*(b));
			pa(&*(a),&*(b));
		}
		else
			rb(&*(b));
	}
	else if ((*b)->next == NULL)
		pa(&*(a),&*(b));
	else
		rrb(&*(b));
}