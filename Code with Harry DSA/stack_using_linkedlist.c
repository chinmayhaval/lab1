#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
int isfull(struct node *top)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
        return 1;
    else
        return 0;
}
int isempty(struct node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
struct node *push(int x)
{
    if (isfull(top))
        printf("stack overflow\n");
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = x;
        ptr->next = top;
        top = ptr;
        return top;
    }
}
int pop()
{
    if (isempty(top))
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        int temp = top->data;
        struct node *p = top;
        top = top->next;
        free(p);
        return temp;
    }
}
void linkedlisttraversal(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int peek(int pos)
{
    struct node *p = top;
    int i = 1;
    for (; (i < pos && p != NULL); i++)
    {
        p = p->next;
    }
    if (p != NULL)
        return p->data;
}
int stackbottom()
{
    struct node *p = top;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}
int main()
{

    printf("opertion on stack\n");
    printf("1:push\n");
    printf("2:pull\n");
    printf("3:peek\n");
    printf("4:print whole stack\n");
    printf("5:top element\n");
    printf("6:bottom element\n");
    printf("7:exit\n");

    int ch = 1;
    do
    {
        printf("enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter element to push:");
            int p;
            scanf("%d", &p);
            push(p);
            break;
        case 2:
            printf("Popped %d from the stack\n", pop());
            break;
        case 3:
            printf("enter position\n");
            int j;
            scanf("%d", &j);
            printf("The value at position %d is %d\n", j, peek(j));
            break;
        case 4:
            // Printing values from the stack
            linkedlisttraversal(top);
            break;
        case 5:
            printf("top value of stack is %d\n", top->data);
            break;
        case 6:
            printf("bottom value of stack is %d\n", stackbottom());
            break;
        case 7:
            break;
        default:
            break;
        }
    } while (ch != 7);
}
