#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    // link node and fill the data
    head->data = 12;
    head->next = first;

    first->data = 16;
    first->next = second;

    second->data = 45;
    second->next = third;

    third->data = 67;
    third->next = fourth;

    fourth->data = 54;
    fourth->next = NULL;

    // calling traversal
    linkedlisttraversal(head);
}