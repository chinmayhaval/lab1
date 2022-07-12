#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter element:");
    scanf("%d", &ptr->data);
    return ptr;
}
struct node *creatlist(struct node *head, int n)
{
    struct node *newnode;
    struct node *p;
    for (int i = 0; i < n; i++)
    {
        newnode = getnode();
        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newnode;
            newnode->next = NULL;
        }
    }
    newnode->next = head;
    return head;
}
void linkedlisttraversal(struct node *head)
{
    struct node *ptr;
    ptr = head;
    printf("elements:");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
int main()
{
    struct node *head = NULL;
    int n;
    scanf("%d", &n);
    head = creatlist(head, n);
    linkedlisttraversal(head);
}