#include <stdio.h>
#include <stdlib.h>
struct array
{
    int total_size;
    int used_size;
    int *ptr;
};
struct array createarray(struct array arr, int tsize, int usize)
{
    arr.total_size = tsize;
    arr.used_size = usize;
    arr.ptr = (int *)malloc(tsize * sizeof(int));
    return arr;
}
void setval(struct array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        scanf("%d", &a->ptr[i]);
    }
}
void show(struct array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d", a->ptr[i]);
    }
    printf("\n");
}

int main()
{
    struct array marks;
    marks = createarray(marks, 20, 5);
    printf("We are running setVal now\n");
    setval(&marks);
    printf("We are running show now\n");
    show(&marks);
}
