#include <stdio.h>
void swap(int *a,int *b){

    int t = *a;
    *a = *b;
    *b = t;
    
}


int main()
{
    int data[] = {3, 4, 1, 2, 5};
    int n = 5;
    int i ,j = 0;

    for (i = n - 1; i > 0; i--){ // i = sorted arr head
        for (j = 1; j <= i; j++){ // swap wrong pair until achive the sorted arr head,like bubble
            if (data[j - 1] > data[j]){
                swap(&data[j - 1], &data[j]);
            }
        }
    }

    for(i = 0;i<n;i++){
        printf("%d ",data[i]);
    }
}