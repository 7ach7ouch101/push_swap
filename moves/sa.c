void    sa(struct Node *head)
{
    int data;

    if(head->next == NULL)
        return ;
    data = head->data;
    head->data = head->next->data;
    head->next->data = data;
}