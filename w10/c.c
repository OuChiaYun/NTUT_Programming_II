#include <stdio.h>
void print(int a[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}
void test002()
{
    int a[] = {5, 4, 3, 2, 1, 0};
    int b[] = {0, 0, 0};
    int *p;
    p = a;
    b[1] = (*(p++))++;
    printf("%d, %d\n", b[1], *p);
    print(a, 6);
}

void test003()
{
    int a[] = {5, 4, 3, 2, 1, 0}, b[] = {0, 0, 0};
    int *p;
    p = a;
    b[1] = ++(*(p++));
    printf("%d, %d\n", b[1], *p);
    print(a, 6);
}
int main()
{
    test002();
    test003();
    return 0;
}