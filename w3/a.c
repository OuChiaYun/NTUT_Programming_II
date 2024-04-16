#include <stdio.h>
#include <stdlib.h>

void fun(int a[]){
    a[0] = 3;
    printf("%p\n",&a[0]);

}

int main()
{
    // int x = 8;
    // int *p;
    // int *n = (int *)malloc(sizeof(int) * 10);
    // for (int i = 0; i < x; i++)*(n + i) = i;
    // p = n;
    // p++;
    // printf("%d, ", (*p)++);                           // (1)
    // printf("jj : %d, ", (*p));   
    // printf("%d, ", ++(*p));                           // (2)
    // printf("%d, ", *(p++));                           // (3)
    // printf("%d, ", *p++);                             // (4)
    // printf("cafe%d,",*p);
    // printf("cafe%d,",*(p+1));
    // printf("\n%d, %d, %d, %d", n[0], n[1], n[2], n[3]); //(5)
    // printf("\n%d\n",3.75);
    // free(n);
    int a[] = {0,1,3};
    fun(a);
    printf("%p\n",&a[0]);
}