#include <stdio.h>

int find2Min(int data[], int size)
{
    int minIndex, index = 0;
    for (int i = 0; i < size; i++)
    {

        if (data[i] < data[minIndex])
            minIndex = i;
    }
    
    if (minIndex == 0)index = 1;

    for (int i = index + 1; i < size; i++)
    {

        if (i != minIndex)
        {
            if (data[i] < data[index])index =i;
        }
    }
    return index;
}
int main()
{
    int data[] = {5, 1, 3, 6, 2};
    printf("2 min=%d\n", find2Min(data, 5));

    return 0;
}