#include <stdio.h>

// void f(int a, int *b, int *c)
// {

//     int d;
//     a = 2;
//     *b = 3;
//     c = &a;
//     d = 5;

//     printf("f:%p %p %p %p\n",&a,b,c,&d);
// }

// void function(int *a, int *b, int *c)
// {
//     int *temp = a;
//     *b = (*c) * (*temp);
//     *c = *temp;
//     *a = 10;
//     a = b;
//     b = c;
//     c = temp;
// }

int main()
{

    // int a = 1, b = 2, c = 3, d = 4;

    // printf("m1:%p %p %p %p\n",&a,&b,&c,&d);
    // f(a, &b, &c);

    // printf("%d %d %d %d\n", a, b, c, d);
    // printf("m2:%p %p %p %p",&a,&b,&c,&d);

    // int i = -1, j = 4, k = 2, *p = &i, *q = &j;
    // function(p, q, &k);
    // printf("%d %d %d\n", i, j, k);
    // printf("%d %d %d\n", *(p++), j, k);
    // printf("%d %d %d\n", i, j, k);
    int a,b;
    scanf("%d/%d",&a,&b);
    printf("%d %d",a,b);
    return 0;
}
