#include <stdio.h>

#define SWAP(x, y) \
    {              \
        int t;     \
        t = x;     \
        x = y;     \
        y = t;     \
    }
int getMinIndex(int d[], int left, int right)
{
    int i = 0, minIndex = left; //the unsorted arr index head
    for ((i = left + 1); i < right; i++) // findall 
    {
        if (d[i] < d[minIndex]) // find the smallist element in the unsorted arr 
            minIndex = i; // make the min Index is i
    }
    return minIndex;
}


/*

sort and unsorted arr will looks like 

1 2 3 | 5    7  4   9  6
      i left    min    right

*/

void selectSort(int d[], int n)
{
    int i = 0, index = 0;
    for (i = 0; i < n; i++) // i ,there is means the tail index of the sorted array
    {
        index = getMinIndex(d, i, n); //find the location of the most small element after i (the sorted arr's tail index)
        printf("%d, %d\n", d[i], d[index]); // just express which pair of elements will be swap
        SWAP(d[i], d[index]); //swap , to make the small element in the sorted arr tail,
    }
}

int main(){
    int d[] = {5,1,3,7,6,2};
    selectSort(d,6);

    for(int i = 0;i<6;i++){
        printf("%d ",d[i]);
    }

}