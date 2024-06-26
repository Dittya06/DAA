
/*  C Program to implement Quick Sort using recursion  */

#include <stdio.h>

void quicksort (int [], int, int);

int main()
{
    int list[50];
    int size, i;

    printf("How many elements u want to Sort :: ");
    scanf("%d", &size);

    printf("\nEnter the elements below to be sorted :: \n");

    for (i = 0; i < size; i++)
    {
        
        scanf("%d", &list[i]);
    }

    quicksort(list, 0, size - 1);

    printf("\nAfter implementing Quick sort, Sorted List is :: \n\n");

    for (i = 0; i < size; i++)
    {
        printf("%d  ", list[i]);
    }

    printf("\n");

    return 0;
}

void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}
