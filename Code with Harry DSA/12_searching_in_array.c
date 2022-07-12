#include <stdio.h>
int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
int bianrysearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(element==arr[mid])
        return mid;
        else if(element>arr[mid])
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
}

int main()
{
    // Unsorted array for linear search
  
    printf("enter your element:");
    int element;
    scanf("%d", &element);
    //Sorted array for binary search
     int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
     int size = sizeof(arr) / sizeof(int);
     int index = bianrysearch(arr, size, element);

    printf("The element %d was found at index %d \n", element, index);
}