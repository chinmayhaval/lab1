#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *getnode()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter your number:");
    scanf("%d", &ptr->data);
    return ptr;
}
struct node *creatlist(int n, struct node *head)
{
    struct node *newnode;
    struct node *p, *q;
    for (int i = 0; i < n; i++)
    {
        newnode = getnode();
        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
            newnode->prev=NULL;
        }
        else
        {
            p = head;
            //q = head->next;
            while (p->next != NULL)
            {
                p = p->next;
               // q = q->next;
            }

            p->next = newnode;
            newnode->prev=p;
            newnode->next = NULL;
        }
    }
    return head;
}
void linkedlisttraversal(struct node *ptr)
{
    printf("elements:");
    while (ptr->next!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
      printf("%d ", ptr->data);
    printf("\n");
   
  do 
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }while(ptr != NULL);
    printf("\n");
}
int main()
{
    struct node *head = NULL;

    printf("enter the number of nodes:");
    int n;
    scanf("%d", &n);
    // (struct node *)malloc(sizeof(struct node));
    head = creatlist(n, head);
    linkedlisttraversal(head);
}