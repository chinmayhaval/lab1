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
    printf("enter your number:");
    scanf("%d", &ptr->data);
    return ptr;
}
struct node *creatlist(int n, struct node *head)
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
                p = p->next;
            p->next = newnode;
            newnode->next = NULL;
        }
    }
    return head;
}
void linkedlisttraversal(struct node *ptr)
{
    printf("elements:");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
void insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
void insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = ptr;
    ptr->next = NULL;
}
struct node *deleteatfirst(struct node *head)
{
    struct node *p;
    printf("deleted element %d\n", head->data);
    p = head;
    head = head->next;
    free(p);
    return head;
}
void deleteatindex(struct node *head, int index)
{
    struct node *p, *q;

    p = head;
    q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    printf("deleted element %d\n", q->data);
    p->next = q->next;
    free(q);
}
void deleteatend(struct node *head)
{
    struct node *p, *q;

    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    printf("deleted element %d\n", q->data);
    p->next = NULL;
    free(q);
}
struct node *reversealist(struct node *head)
{
    struct node *prev, *temp, *current;
    prev = NULL;
    current = head;
    //temp = head->next;
    while (current!=NULL)
    {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
        // temp=temp->next;
    }
    head=prev;
    return head;
}

/*void insertafternode(struct node *head, struct node *prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p != prevnode)
    {
        p = p->next;
    }
    ptr->next =
}*/
int main()
{
    struct node *head = NULL;
    /*printf("enter the number of nodes:");
    int n;
    scanf("%d", &n);
    struct node *head = NULL; // (struct node *)malloc(sizeof(struct node));
    head = creatlist(n, head);
    // struct node *first = (struct node *)malloc(sizeof(struct node));
    // struct node *second = (struct node *)malloc(sizeof(struct node));
    // struct node *third = (struct node *)malloc(sizeof(struct node));
    // struct node *fourth = (struct node *)malloc(sizeof(struct node));

    // link node and fill the data
    /* head->data = 12;
     head->next = first;

     first->data = 16;
     first->next = second;

     second->data = 47;
     second->next = third;

     third->data = 67;
     third->next = fourth;

     fourth->data = 54;
     fourth->next = NULL;*/

    // calling traversal*/
    printf("operation on linkedlist\n1:create list\n2:show\n3:insert at first\n4:insert at index\n5:insert at end\n");
    printf("6:delete at first\n7:delete at index\n8:delete at end\n9:reverse list\n10:exit\n");
    int input;

    do
    {
        printf("enter the choice:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("enter the number of nodes:");
            int n;
            scanf("%d", &n);
            // (struct node *)malloc(sizeof(struct node));
            head = creatlist(n, head);
            break;
        case 2:
            linkedlisttraversal(head);
            break;
        case 3:
            printf("enter the number:\n");
            int a;
            scanf("%d", &a);
            head = insertatfirst(head, a);
            break;
        case 4:
            printf("enter at index:\n");
            int c;
            int b;
            scanf("%d", &c);
            printf("enter the number:\n");
            scanf("%d", &b);
            insertatindex(head, b, c);
            break;
        case 5:
            printf("enter the number:\n");
            int d;
            scanf("%d", &d);
            insertatend(head, d);
            break;

        case 6:
            head = deleteatfirst(head);
            break;
        case 7:
            printf("enter at index:");
            int f;
            scanf("%d", &f);
            deleteatindex(head, f);
            break;
        case 8:
            deleteatend(head);
            break;
        case 9:
            head = reversealist(head);
        case 10:
            break;
        default:
            printf("invalid choice\nenter the appropriate choice!\n");
            break;
        }
    } while (input != 10);

    /*linkedlisttraversal(head);
    // insert at beginnig
    printf("\ninsert at beginning:\n");
    int a;
    scanf("%d", &a);
    head = insertatfirst(head, a);
    linkedlisttraversal(head);
    // insert at index,index starting from 0
    printf("\ninsert at index:\n");
    int b;
    scanf("%d", &a);
    printf("enter the number:\n");
    scanf("%d", &b);
    insertatindex(head, b, a);
    linkedlisttraversal(head);
    // insert at end,index starting from 0
    printf("\ninsert at end:\n");
    scanf("%d", &a);
    insertatend(head, a);
    linkedlisttraversal(head);
    // Insertion after a given node:
    // printf("\ninsert after node\n");
    // insertafternode(head, second, 45);
    // linkedlisttraversal(head);*/
}