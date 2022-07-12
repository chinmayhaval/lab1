#include <stdio.h>
#include <stdlib.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int indinsert(int arr[], int index, int element, int size)
{
    if (index >= size)
        return 0;
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int inddelete(int arr[], int index, int size)
{
    if (index >= size)
        return 0;
    for (int i = index; i <= size - 2; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}
int main()
{
    int arr[100] = {43, 64, 38, 59, 34, 38};
    int size = 5, element, index;
    display(arr, size);
    printf("type element to insert\n");
    scanf("%d", &(element));
    printf("type index\n");
    scanf("%d", &(index));
    int check = indinsert(arr, index, element, size);
    size++;
    if (check)
        display(arr, size);
    else
        printf("program failed\n");
    printf("type index to to delete\n");
    scanf("%d", &(index));
    check = inddelete(arr, index, size);
    size--;
    if (check)
        display(arr, size);
    else
        printf("program failed\n");
}
