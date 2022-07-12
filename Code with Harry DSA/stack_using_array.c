#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("stack overflow!can't insert\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack underflow!can't pull\n");
        return -1;
    }
    else
    {
        int element = ptr->arr[ptr->top];
        ptr->top--;
        return element;
    }
}
int peek(struct stack *ptr, int pos)
{
    int index = ptr->top - pos + 1;
    if (index < 0)
        printf("invalid position\n");
    else
    {
        return ptr->arr[index];
    }
}
int main()
{
    struct stack mark;
    mark.top = -1;
    printf("enter the size of stack\n");
    scanf("%d", &mark.size);
    mark.arr = (int *)malloc(mark.size * sizeof(int));
    printf("opertion on stack\n");
    printf("1:push\n");
    printf("2:pull\n");
    printf("3:peek\n");
    printf("4:print whole array\n");
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
            push(&mark, p);
            break;
        case 2:
            printf("Popped %d from the stack\n", pop(&mark));
            break;
        case 3:
            printf("enter position\n");
            int j;
            scanf("%d", &j);
            printf("The value at position %d is %d\n", j, peek(&mark, j));
            break;
        case 4:
            // Printing values from the stack
            for (int j = 1; j <= mark.top + 1; j++)
            {
                printf("%d ", peek(&mark, j));
            }
            printf("\n");
            break;
        case 5:
            printf("top value of stack is %d\n", mark.arr[mark.top]);
            break;
        case 6:
            printf("bottom value of stack is %d\n", mark.arr[0]);
            break;
        case 7:
            break;
        default:
            break;
        }
    } while (ch != 7);
}
