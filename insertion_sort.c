#include<stdio.h>

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void insertionSort(int a[], int n)
{
    int target = 0, i = 0, j = 0;
    for (i = 1; i < n; i++)
    {
        target = a[i];
        for (j = i; (a[j - 1] > target) && (j > 0); j--) //if a[j - 1] < target, mean you don't nedd to move other element in sorted arr
            a[j] = a[j - 1]; // to move the tail of sorted arr, then we can put the target in the correct place 
        a[j] = target;
        print(a, n);
    }
}

int main()
{
    int a[] = {89, 78, 54, 16, 64, 3, 47, 68, 90, 97};
    insertionSort(a, 10);
    return 0;
}